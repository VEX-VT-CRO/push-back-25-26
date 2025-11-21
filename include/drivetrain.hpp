#ifndef __DRIVETRAIN_HPP__
#define __DRIVETRAIN_HPP__

#include "api.h"
#include "main.h"
#include "lemlib/api.hpp"

class Drivetrain {
public:
    // Constructor
    Drivetrain(
        int fl, int mfl, int mbl, int bl,     // Left motors
        int fr, int mfr, int mbr, int br,     // Right motors
        int imuPort,                           // IMU port
        int leftEncPort,                       // Left rotation sensor port
        int rightEncPort,                      // Right rotation sensor port
        pros::motor_brake_mode_e_t brakeMode = pros::E_MOTOR_BRAKE_BRAKE
    );

    // Manual drive
    void tank(int leftPower, int rightPower, int deadband = 0);
    void arcade(int forward, int turn, int deadband = 0);

    // Pose and movement
    void setPose(float x, float y, float heading);
    void moveTo(float x, float y, int timeout);
    void turnToHeading(float heading, int timeout);
    void turnToPoint(float x, float y, int timeout);

    // Calibration
    void calibrate();

    // Access underlying LemLib chassis
    lemlib::Chassis* getChassis();

private:
    // -----------------
    // Motors
    // -----------------
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

    // -----------------
    // Sensors
    // -----------------
    pros::Imu imu;
    pros::Rotation leftEnc;
    pros::Rotation rightEnc;

    // -----------------
    // LemLib Tracking Wheels
    // -----------------
    lemlib::TrackingWheel leftWheel;
    lemlib::TrackingWheel rightWheel;

    // -----------------
    // LemLib Objects
    // -----------------
    lemlib::OdomSensors odomSensors;
    lemlib::Drivetrain drivetrainCfg;
    lemlib::Chassis chassis;
};

#endif
