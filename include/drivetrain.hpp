#ifndef __DRIVETRAIN_HPP__
#define __DRIVETRAIN_HPP__
#include "api.h"

class Drivetrain {
    // Constructor for an 8-motor tank; adjust ports/signs to your build.
    public: 
    Drivetrain(
        int fl, int mfl, int mbl, int bl,
        int fr, int mfr, int mbr, int br,
        pros::motor_brake_mode_e_t brakeMode = pros::E_MOTOR_BRAKE_BRAKE
    )   
        // Motor rotations so that positive moves forward and vice versa
        : left({(int8_t)-fl, (int8_t)-mfl, (int8_t)mbl, (int8_t)bl})
        , right({(int8_t)fr, (int8_t)mfr, (int8_t)-mbr, (int8_t)-br})
    {
        left.set_brake_mode_all(brakeMode);
        right.set_brake_mode_all(brakeMode);
    }

    // Basic drive
    void tank(int leftPower, int rightPower) {
        left.move(leftPower);
        right.move(rightPower);
    }

    // Direct control helpers
    void setBrakeMode(pros::motor_brake_mode_e_t mode) {
        left.set_brake_mode_all(mode);
        right.set_brake_mode_all(mode);
    }

private:
    pros::MotorGroup left;
    pros::MotorGroup right;
};


#endif