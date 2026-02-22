#ifndef __DRIVETRAIN_HPP__
#define __DRIVETRAIN_HPP__

#include "api.h"
#include "pros/motors.hpp"

// forward-declare lemlib::Chassis to keep API compatibility
namespace lemlib { class Chassis; }

class Drivetrain {
public:
    // Constructor
    Drivetrain(
        int fl, int mfl, int mbl, int bl,     // Left motors
        int fr, int mfr, int mbr, int br,     // Right motors
        int imuPort,                          // unused in sensor-free mode (kept for API)
        int leftEncPort,                      // unused (kept for API)
        int rightEncPort,                     // unused (kept for API)
        pros::motor_brake_mode_e_t brakeMode = pros::E_MOTOR_BRAKE_BRAKE
    );

    // Manual drive
    void tank(int leftPower, int rightPower, int deadband = 0);
    void arcade(int forward, int turn, int deadband = 0);

    // Pose and movement (no-op in sensor-free mode, present for API compatibility)
    void setPose(float x, float y, float heading);
    void moveTo(float x, float y, int timeout);
    void turnToHeading(float heading, int timeout);
    void turnToPoint(float x, float y, int timeout);

    // Calibration (no-op in sensor-free mode)
    void calibrate();

    // Access underlying LemLib chassis (returns nullptr in sensor-free mode)
    lemlib::Chassis* getChassis();

private:
    // Drive motors
    pros::Motor frontLeft;
    pros::Motor middleFrontLeft;
    pros::Motor middleBackLeft;
    pros::Motor backLeft;

    pros::Motor frontRight;
    pros::Motor middleFrontRight;
    pros::Motor middleBackRight;
    pros::Motor backRight;

    pros::MotorGroup leftMotors;
    pros::MotorGroup rightMotors;

    // We keep a pointer for lemlib chassis to preserve API; it's nullptr in sensor-free build.
    lemlib::Chassis* chassis = nullptr;
};

#endif // __DRIVETRAIN_HPP__
