/**
 * @file test.cpp
 * @author Rashmi Kapu (rashmik@umd.edu), Neha Madhekar (nehanm97@umd.edu)
 * @brief Unit tests for PID controller implementation : compute() function
 * @version 0.1
 * @date 2023-10-09
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>

#include "../include/pid.hpp"

PID_controller pid_test;

TEST(compute, this_should_pass) {
  EXPECT_NEAR(pid_test.compute(10.0), 10.0, 0.2);
}

TEST(compute, this_should_pass_too) { 
  ASSERT_GT(pid_test.compute(100.0), 25.0); 
}
TEST(check, this_should_always_pass) { 
 ASSERT_TRUE(pid_test.check(10.0,1.0,2.0,1.0,0.9)); 
}
TEST(check, this_should_always_pass1) { 
 ASSERT_FALSE(pid_test.check(-10.0,1.0,2.0,1.0,0.9)); 
}
TEST(check, this_should_always_pass2) { 
 ASSERT_FALSE(pid_test.check(10.0,-1.0,-2.0,1.0,0.9)); 
}
