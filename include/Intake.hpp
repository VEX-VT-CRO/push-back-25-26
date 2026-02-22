#ifndef INTAKE_HPP_
#define INTAKE_HPP_

#include "pros/motors.hpp"
#include "pros/adi.hpp"

class Intake {
    enum SPEED_SETTING {OFF = 0, FORWARD = 100, REVERSE = -100};

public:
    Intake(int flywheel_port_1, int flywheel_port_2, char pneumatic_port);

    void Spin();
    void Reverse();
    void Stop();

    void Retract();
    void Extend();

private:
    pros::Motor flywheel_1_;
    pros::Motor flywheel_2_;
    pros::adi::Pneumatics pneumatic_;
};

#endif
