#include "main.h"
#include "Drivetrain.hpp"

//CONSTANTS GO HERE
constexpr int FRONT_LEFT_PORT         = 2;
constexpr int MIDDLE_FRONT_LEFT_PORT  = 3;
constexpr int MIDDLE_BACK_LEFT_PORT   = 4;
constexpr int BACK_LEFT_PORT          = 5;

constexpr int FRONT_RIGHT_PORT        = 9;
constexpr int MIDDLE_FRONT_RIGHT_PORT = 8;
constexpr int MIDDLE_BACK_RIGHT_PORT  = 7;
constexpr int BACK_RIGHT_PORT         = 6;

constexpr int IMU_PORT = 10;
constexpr int LEFT_ENCODER_PORT        = 1; 
constexpr int RIGHT_ENCODER_PORT       = 2;

//INITIALIZE SUBSYSTEMS HERE
pros::Controller driver(pros::E_CONTROLLER_MASTER);

Drivetrain drive(
    FRONT_LEFT_PORT, MIDDLE_FRONT_LEFT_PORT, MIDDLE_BACK_LEFT_PORT, BACK_LEFT_PORT,
    FRONT_RIGHT_PORT, MIDDLE_FRONT_RIGHT_PORT, MIDDLE_BACK_RIGHT_PORT, BACK_RIGHT_PORT,
    IMU_PORT,
    LEFT_ENCODER_PORT,
    RIGHT_ENCODER_PORT,
    pros::E_MOTOR_BRAKE_BRAKE
);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");
    drive.calibrate();
    pros::lcd::set_text(1, "Init done");
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
    while (true) {
        int forward = driver.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int turn    = driver.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // arcade drive
        drive.arcade(forward, turn, 15);

        pros::delay(10);
    }
}