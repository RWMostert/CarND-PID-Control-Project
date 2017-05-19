#include "PID.h"
#include <iostream>

using namespace std;

PID::PID() {}

PID::~PID() {}

/**
    Creates the PID controller and sets the values of the P, I and D parameters.

    @param Kp the P-parameter. This is the influence of the direct cross-track-error measurement
    on the steering angle. Hence, this value determines to what degree the size of the cross-track
    error will affect the steering value.
    @param Ki the I-parameter. The I parameter defines the influence of the sum of the cross-track
    errors on the steering measurement (the integral of the cross-track errors over time).
    The I-parameter helps correct any steering biases over time. This parameter value should
    usually be very small. The idea being that for a car with some steering bias (either steering
    to the left / to the right), the I-parameter defines the speed with which this is corrected.
    @param Kd the D-parameter. This is the influence of the change in the cross-track error measurement
    on the steering angle (the first derivative). This tends to control the "smoothness" of the steering
    and prevents an overshoot.
    @return an initialized pid instance.
*/

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    p_error = 0;
    i_error = 0;
    d_error = 0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    return  - Kp * p_error - Kd * d_error - Ki * i_error;
}

