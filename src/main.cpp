#include "main.h"
#include "api.h"
#include "robodash/api.h"
#include "robodash/views/console.hpp"

/******************************************************************************
 *                              Motor Definitions
 ******************************************************************************/
// Drive Train
pros::Motor Back_left(1, pros::v5::MotorGears::blue);
pros::Motor Front_left(10, pros::v5::MotorGears::blue);
pros::Motor front_right(-11, pros::v5::MotorGears::blue);
pros::Motor back_right(-20, pros::v5::MotorGears::blue);
pros::Motor Top_front_Left(, pros::v5::MotorGears::green);
pros::Motor Top_front_Right(, pros::v5::MotorGears::green);
pros::Motor Top_back_Left(, pros::v5::MotorGears::green);
pros::Motor Top_back_Right(, pros::v5::MotorGears::green);


/******************************************************************************
 *                              Function Prototypes
 ******************************************************************************/
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}


// Declare console pointer at file scope
rd::Console* console = nullptr;

void initialize() {
    console = new rd::Console("Motor Temps");
} 

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    
    while (true) {
        // RoboDash monitoring
       console->println("Back_left: " + std::to_string(Back_left.get_temperature()));
       console->println("Front_left: " + std::to_string(Front_left.get_temperature()));
       console->println("Front_right: " + std::to_string(front_right.get_temperature()));
       console->println("Back_right: " + std::to_string(back_right.get_temperature()));
	   console->println("Top_front_Left: " + std::to_string(Top_front_Left.get_temperature()));
	   console->println("Top_front_Right: " + std::to_string(Top_front_Right.get_temperature()));
	   console->println("Top_back_Left: " + std::to_string(Top_back_Left.get_temperature()));
	   console->println("Top_back_Right: " + std::to_string(Top_back_Right.get_temperature()));
        drive_control(master);
        pros::delay(20); // 50Hz loop
    }
}


void drive_control(pros::Controller& master) {
    int y = -master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int x = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    int turn = -master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    
    Back_left.move(y + x + turn);
    Front_left.move(y - x + turn);
    back_right.move(y - x - turn);
    front_right.move(y + x - turn);
}