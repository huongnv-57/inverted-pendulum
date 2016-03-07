#include <iostream>
#include <cmath>
#include "pid.h"

using namespace std;


PID::PID( double dt, double max, double min, double Kp, double Kd, double Ki ) :
    _dt(dt),
    _max(max),
    _min(min),
    _Kp(Kp),
    _Kd(Kd),
    _Ki(Ki),
    _pre_error(0),
    _integral(0)
{
}
PID::PID(){
    _dt=0;
    _max =0;
    _min =0;
    _Kp=1;
    _Kd =1;
    _Ki =1;
    _pre_error =0;
    _integral =0;
}

double PID::calculate( double setpoint, double pv )
{

    // Calculate error
    double error = setpoint - pv;

    // Proportional term
    double Pout = _Kp * error;

    // Integral term
    _integral += error * _dt;
    double Iout = _Ki * _integral;

    // Derivative term
    double derivative = (error - _pre_error) / _dt;
    double Dout = _Kd * derivative;

    // Calculate total output
    double output = Pout + Iout + Dout;

    // Restrict to max/min
    if( output > _max )
        output = _max;
    else if( output < _min )
        output = _min;

    // Save error to previous error
    _pre_error = error;

    return output;
}
void PID::setup(double dt, double max, double min, double Kp, double Kd, double Ki){
    this->_dt=dt;
    this->_max=max;
    this->_min=min;
    this->_Kp=Kp;
    this->_Kd=Kd;
    this->_Ki=Ki;
    this->_pre_error=0;
    this->_integral=0;
}
double PID::getErr(){
    return _pre_error;
}
