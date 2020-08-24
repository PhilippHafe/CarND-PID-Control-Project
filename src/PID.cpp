#include "PID.h"
#include <limits>
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  PID::Kp = Kp_;
  PID::Ki = Ki_;
  PID::Kd = Kd_;

  p_error = 0;
  i_error = 0;
  d_error = 0;

  // Initialize cte and counters
  prev_cte = 0;
  counter = 0;
  sum_err = 0;
  min_err = std::numeric_limits<double>::max();
  max_err = std::numeric_limits<double>::min();

}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;

  i_error += cte;

  d_error = cte - prev_cte;

  prev_cte = cte;

  sum_err += cte;
  counter++;

  if (cte > max_err){
    max_err = cte;
  }

  if (cte < min_err){
    min_err = cte;
  }

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return p_error * Kp + i_error * Ki + d_error * Kd;  // TODO: Add your total error calc here!
}