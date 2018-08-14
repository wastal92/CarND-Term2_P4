#include <iostream>
#include "PID.h"
#include "float.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    cte_prev = DBL_MAX;
}

void PID::UpdateError(double cte) {
    if (cte_prev == DBL_MAX){
        cte_prev = cte;
    }
    p_error = cte;
    d_error = cte - cte_prev;
    cte_prev = cte;
    i_error +=  cte;
}

double PID::TotalError() {
    total_error = Kp*p_error + Kd*d_error + Ki*i_error;
    return total_error;
}

