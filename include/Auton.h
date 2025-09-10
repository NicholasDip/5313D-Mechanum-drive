#pragma once

#include "main.h"
#include "robodash/api.h"

/**
 * @brief Autonomous function declarations
 */

// Autonomous routines
void red_left_auton();
void red_right_auton();
void blue_left_auton();
void blue_right_auton();
void skills_auton();

// Robodash selector (declared in auton.cpp)
extern rd::Selector selector;
