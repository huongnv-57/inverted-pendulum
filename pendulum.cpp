#include "pendulum.h"
#include <cmath>
#include <QDebug>
#include <iostream>
#define PI  3.14159265
#include "pid.h"

using namespace std;

Pendulum::Pendulum(double angle, double position){
    M = 0.5;
    m = 0.5;
    b = 0.1;
    I = 0.006;
    g = 9.8;
    l = 0.3;
    dt =0.01;
    dx =0;
    da =0;
    F=0;
    this->angle = (angle*PI/180.0)+PI;
    this->x =position;
    control.setup(dt,100,-100,100,1,20);
}


double Pendulum::getAng(){
    if (angle >= PI){
        return -(angle-PI)*180/PI;
    }else{
        return (PI-angle)*180/PI;
    }
}
double Pendulum::getPosn(){
    return x*600 + 350;// in image
}
//void Pendulum::calNext(){
//    static int i =0;
//    i++;
//    angle += 0.002;
//    //position += -pow(-1.0,double(i)) *100*exp(-2*0.1*i);


//}
void Pendulum::calNext(){

   double phi;
   if (angle >= PI){
       phi=(angle-PI);
   }else{
       phi=-(PI-angle);
   }
   //qDebug()<<phi;
   double output = F-control.calculate(0,phi);
   //qDebug()<<"ka"<<output;
   //denominator
   double den = I*(M+m)+M*m*pow(l,2);

   //2nd deviation of x
   double ddx = (-dx*(I +m*pow(l,2))*b)/den + phi*pow(m,2)*g*pow(l,2)/den + output*(I+m*pow(l,2))/den;

   //2nd deviation of angle
   double dda = -dx*m*l*b/den + phi*m*g*l*(M+m)/den + m*l*output;

   //calculate dx, da;
   dx = dx +ddx*dt;
   da = da + dda*dt;

   //calculate angle;

   phi += -dx*dt - ddx*dt*dt/2;
   angle = PI+phi;
   if(angle >=2*PI){
       angle = angle-2*PI;
   }
    if (output>=0){
        x+= -dx*dt-ddx*dt*dt/2;
    }else{
        x+= +dx*dt+ddx*dt*dt/2;
    }

//   F = F-control.calculate(0,phi);
   qDebug()<<"x:"<<x*100<<"\t"<<"angle:"<<getAng()<<"dau: "<<output;
}

double Pendulum::getErr(){
    return control.getErr();
}
