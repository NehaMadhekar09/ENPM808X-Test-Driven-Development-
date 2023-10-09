/**
 * @file pid.cpp
 * @author Rashmi Kapu (rashmik@umd.edu), Neha Madhekar (nehanm97@umd.edu)
 * @brief To initialise the members variables of the class 'PID_Controller' and implement the member functions
 * @version 0.1
 * @date 2023-10-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../include/pid.hpp"

/**
 * @brief Computes the output of the PID controller
 * 
 * @param vel : double
 * @return double 
 */
double PID_controller::compute(double vel) {
  double initial_vel = vel;
  
  // Proportional Error
  double error = expected_vel - initial_vel;
  // Derivative Error
  double d_error = (error - prev_error)/deltaT;
  // Integral Error
  double i_error = prev_error * deltaT + (error - prev_error) * deltaT/2;

  // Solve for output Velocity based on PID Controller
  double output_vel = Kp * error + Kd * d_error + Ki*(i_error) + initial_vel;
  
  // Update Previous Error
  prev_error = error;
 
  return output_vel;
  // return 0.0;
}

/**
 * @brief Construct a new pid controller::pid controller object
 * 
 */
PID_controller::PID_controller() {
  PID_controller::Kp = 0.5;
  PID_controller::Kd = 0.011;
  PID_controller::Ki = 0.01;
  PID_controller::initial_vel = 0.0;
}

/**
 * @brief To set the expected velocity
 * 
 * @param expected_result : double
 */
void PID_controller::set_expected_velocity(double expected_result) {
  PID_controller::expected_vel = expected_result;
}
