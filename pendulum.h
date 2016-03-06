#ifndef PENDULUM_H
#define PENDULUM_H
#include "pid.h"

class Pendulum
{
public:
    float M, m;     //mass (kg)
    float g;        //gravity
    float rodLen;
    double angle;     //rad
    double position;  //0 at pixel 350
    PID control;

public:
    Pendulum(double angle, double position);
    Pendulum(float M, float m, float g, float rodLen,double angle, double position);
    double getPosn();
    double getAng();

    //function to calculate the next posn and angle
    void calNext();



};



#endif // PENDULUM_H
