#include "Drivetrain.hpp"
#include "main.h"
extern pros::Controller driver;

// PID settings
static const lemlib::ControllerSettings LINEAR_PID(
    0.3, 0.0, 0.0,
    100,
    1,
    10,
    1.0,
    0.0,
    1.0
);

static const lemlib::ControllerSettings ANGULAR_PID(
    4.0, 0.0, 0.0,
    100,
    1,
    10,
    180.0,
    0.0,
    180.0
);

Drivetrain::Drivetrain(
    int fl, int mfl, int mbl, int bl,
    int fr, int mfr, int mbr, int br,
    int imuPort,
    int leftEncPort,
    int rightEncPort,
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

    , imu(imuPort)
    , leftEnc(leftEncPort)
    , rightEnc(rightEncPort)

    , leftWheel(&leftEnc, 2.75, -5.0)
    , rightWheel(&rightEnc, 2.75, 5.0)

    , odomSensors(&leftWheel, &rightWheel, nullptr, nullptr, &imu)

    , drivetrainCfg(&leftMotors, &rightMotors, 10.0f, 3.25f, 360.0f, 0.0f)

    , chassis(drivetrainCfg, LINEAR_PID, ANGULAR_PID, odomSensors) // ✅ Correct
{
    // Reverse right motors
    frontRight.set_reversed(true);
    middleFrontRight.set_reversed(true);
    middleBackRight.set_reversed(true);
    backRight.set_reversed(true);

    // Reverse encoder directions if needed
    leftEnc.set_reversed(true);
    rightEnc.set_reversed(false);

    leftMotors.set_brake_mode_all(brakeMode);
    rightMotors.set_brake_mode_all(brakeMode);
}

// -----------------
// Drive functions
// -----------------
void Drivetrain::tank(int leftPower, int rightPower, int deadband) {
    chassis.tank(leftPower, rightPower, deadband);
}

void Drivetrain::arcade(int forward, int turn, int deadband) {
    chassis.arcade(forward, turn, deadband);
}

void Drivetrain::setPose(float x, float y, float heading) {
    chassis.setPose(x, y, heading);
}

void Drivetrain::moveTo(float x, float y, int timeout) {
    chassis.moveToPoint(x, y, timeout);
}

void Drivetrain::turnToHeading(float heading, int timeout) {
    chassis.turnToHeading(heading, timeout);
}

void Drivetrain::turnToPoint(float x, float y, int timeout) {
    chassis.turnToPoint(x, y, timeout);
}

void Drivetrain::calibrate() {
    imu.reset();
    while (imu.is_calibrating()) pros::delay(10);
    chassis.calibrate();
}

lemlib::Chassis* Drivetrain::getChassis() {
    return &chassis;
}
