#ifndef PENDULUM_H
#define PENDULUM_H
#include "pid.h"

class Pendulum
{
private:
    float M, m;     //mass (kg)
    float g;        //gravity
    float l;
    double angle;     //rad
    double b, I;
    double x;  //0 at pixel 350
    double dx;
    double da;
    double dt;
    double F;
    PID control;
public:
    Pendulum(double angle, double position);
    double getPosn();
    double getAng();
    double getErr();

    //function to calculate the next posn and angle
    void calNext();
};



#endif // PENDULUM_H
