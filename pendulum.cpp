#include "pendulum.h"
#include <cmath>
#include <QDebug>

#define PI  3.14159265

Pendulum::Pendulum(double angle, double position)
{
    M =2.0;
    m =0.1;
    g =9.81;
    rodLen = 0.5;

    //degree2rad
    angle = angle*PI/180;
    this->angle = angle;
    this->position = position ;

    control.setRefreshInterval(0.02);
    control.setDesiredPoint(0.0);
    control.setErrorThreshold(0.001);
    control.setOutputLowerLimit(-1);
    control.setOutputUpperLimit(1);
    control.setWeights(0.0001,0.000001,0.0001);
    control.setv(0.0);

}
Pendulum::Pendulum(float M, float m, float g, float rodLen, double angle, double position){
    this-> M =M;
    this->m =m;
    this-> g =g;
    this->rodLen = rodLen;
    this-> angle = angle;
    this-> position = position;
}

double Pendulum::getAng(){
    return angle * 180/PI;
}
double Pendulum::getPosn(){
    return position + 350;// in image
}
//void Pendulum::calNext(){
//    static int i =0;
//    i++;
//    angle += pow(-1.0,double(i)) *1.15*exp(-2*0.1*i);
//    position += -pow(-1.0,double(i)) *100*exp(-2*0.1*i);


//}
void Pendulum::calNext(){
   float deltaPos = control.refresh(angle);
   position += -deltaPos*220/0.00266985;

   //calculate new tilt value at new position
   //update new angle;
    static int i =0;
    i++;
    angle += pow(-1.0,double(i))*1.15*exp(-2*0.1*i);


//    float del2angle,delangle,f;
//    delangle = (angle-control.getLastErr())/0.02;
//    f = -deltaPos;
//    del2angle = (-f*cos(angle) - M*rodLen*pow(delangle,2.0) * cos(angle)* sin(angle) -(m+M)*g*sin(angle) )/(rodLen*(M + m*pow(sin(angle),2)));
//    angle = control.getLastErr() + delangle*0.02 - del2angle*pow(0.02,2);

//    float v_new,a,temp;
//    v_new= -deltaPos/0.02;
//    a = (v_new-control.getv())/0.02;

//    angle = asin(M*a-deltaPos)/(m*g);
//    control.setv(v_new);
//    qDebug()<<temp;


}



