#include "Drivetrain.hpp"
#include "main.h"

// Note: we intentionally do NOT include or construct any sensors (IMU, Rotation, TrackingWheel, etc.)
// This file provides a sensor-free drivetrain that only uses motors/motorgroups.
// Movement functions that would require sensors (moveTo, turnToHeading, etc.) are left as no-ops.

Drivetrain::Drivetrain(
    int fl, int mfl, int mbl, int bl,
    int fr, int mfr, int mbr, int br,
    int /*imuPort*/,
    int /*leftEncPort*/,
    int /*rightEncPort*/,
    pros::motor_brake_mode_e_t brakeMode
)
    : frontLeft(fl)
    , middleFrontLeft(mfl)
    , middleBackLeft(mbl)
    , backLeft(bl)

    , frontRight(fr)
    , middleFrontRight(mfr)
    , middleBackRight(mbr)
    , backRight(br)

    , leftMotors({(int8_t)fl, (int8_t)mfl, (int8_t)mbl, (int8_t)bl})
    , rightMotors({(int8_t)fr, (int8_t)mfr, (int8_t)mbr, (int8_t)br})

    , chassis(nullptr)
{
    // Reverse right motors to match mechanical wiring (keeps previous behavior)
    frontRight.set_reversed(true);
    middleFrontRight.set_reversed(true);
    middleBackRight.set_reversed(true);
    backRight.set_reversed(true);

    // Set brake modes for motor groups
    leftMotors.set_brake_mode_all(brakeMode);
    rightMotors.set_brake_mode_all(brakeMode);
}

// -----------------
// Drive functions
// -----------------
void Drivetrain::tank(int leftPower, int rightPower, int /*deadband*/) {
    leftMotors.move(leftPower);
    rightMotors.move(rightPower);
}

void Drivetrain::arcade(int forward, int turn, int /*deadband*/) {
    // simple arcade mixing to stay compatible with previous usage
    int left = forward + turn;
    int right = forward - turn;
    leftMotors.move(left);
    rightMotors.move(right);
}

// -----------------
// API-compatible no-ops for sensor functions
// -----------------
void Drivetrain::setPose(float /*x*/, float /*y*/, float /*heading*/) {
    // NO-OP in sensor-free build
}

void Drivetrain::moveTo(float /*x*/, float /*y*/, int /*timeout*/) {
    // NO-OP in sensor-free build
}

void Drivetrain::turnToHeading(float /*heading*/, int /*timeout*/) {
    // NO-OP in sensor-free build
}

void Drivetrain::turnToPoint(float /*x*/, float /*y*/, int /*timeout*/) {
    // NO-OP in sensor-free build
}

void Drivetrain::calibrate() {
    // NO-OP in sensor-free build (do not touch sensors)
}

lemlib::Chassis* Drivetrain::getChassis() {
    return nullptr; // keep return type stable for other code, but no chassis exists
}
