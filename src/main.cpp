#include "main.h"
#include "Drivetrain.hpp"
#include "Intake.hpp"
#include "Outtake.hpp"
#include "Conveyer.hpp"

// -----------------------------
// CONSTANTS
// -----------------------------
constexpr int FRONT_LEFT_PORT         = -11;
constexpr int MIDDLE_FRONT_LEFT_PORT  = 12;
constexpr int MIDDLE_BACK_LEFT_PORT   = -13;
constexpr int BACK_LEFT_PORT          = 14;

constexpr int FRONT_RIGHT_PORT        = 5;
constexpr int MIDDLE_FRONT_RIGHT_PORT = -4;
constexpr int MIDDLE_BACK_RIGHT_PORT  = -3;
constexpr int BACK_RIGHT_PORT         = 2;

// NO IMU, NO ENCODERS
constexpr int IMU_PORT = -1;
constexpr int LEFT_ENCODER_PORT  = -1;
constexpr int RIGHT_ENCODER_PORT = -1;

// Intake / Outtake
constexpr int INTAKE_PORT_1 = -

10;
constexpr int INTAKE_PORT_2 = 21;
constexpr char INTAKE_PNEUMATIC_PORT = 'A';

constexpr int OUTTAKE_FLYWHEEL_PORT = 20;

// Conveyor motors
constexpr int CONVEYOR_MOTOR_1 = 8;
constexpr int CONVEYOR_MOTOR_2 = -6;

// -----------------------------
// SUBSYSTEMS
// -----------------------------
pros::Controller driver(pros::E_CONTROLLER_MASTER);

Drivetrain drive(
    FRONT_LEFT_PORT, MIDDLE_FRONT_LEFT_PORT, MIDDLE_BACK_LEFT_PORT, BACK_LEFT_PORT,
    FRONT_RIGHT_PORT, MIDDLE_FRONT_RIGHT_PORT, MIDDLE_BACK_RIGHT_PORT, BACK_RIGHT_PORT,
    0,   // IMU disabled
    0,   // encoder dummy
    0,   // encoder dummy
    pros::E_MOTOR_BRAKE_BRAKE
);

Intake intake(INTAKE_PORT_1, INTAKE_PORT_2, INTAKE_PNEUMATIC_PORT);
Outtake outtake(OUTTAKE_FLYWHEEL_PORT);
Conveyer conveyor(CONVEYOR_MOTOR_1, CONVEYOR_MOTOR_2);

// -----------------------------
// INITIALIZE
// -----------------------------
void initialize() {
    pros::lcd::initialize();
    pros::lcd::set_text(1, "Init...");


    pros::lcd::set_text(1, "Init Complete");
}

void disabled() {}
void competition_initialize() {}


// -----------------------------
// AUTON — NO SENSORS
// -----------------------------
void autonomous() {
    
}


// -----------------------------
// DRIVER CONTROL (TANK DRIVE)
// -----------------------------
void opcontrol() {
    while (true) {

        // ----------- TANK DRIVE -----------
        int forward  = driver.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int turn = driver.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);


        drive.arcade(forward, turn, 15);

        // ----------- OUTTAKE -----------
        if (driver.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            outtake.Spin();
        } 
        else {
            outtake.Stop();
        }


        // ----------- CONVEYOR AND INTAKE -----------
        // L1 = run intake + conveyor forward
if (driver.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
    intake.Spin();
    conveyor.upper_forward();
    conveyor.lower_forward();
}
// R1 = reverse intake + conveyor
else if (driver.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
    intake.Reverse();
    conveyor.upper_reverse();
    conveyor.lower_reverse();
}
else {
    intake.Stop();
    conveyor.upper_brake();
    conveyor.lower_brake();
}


        pros::delay(10);
    }
}
