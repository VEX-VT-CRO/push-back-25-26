#include "Intake.hpp"

Intake::Intake(int flywheel_port_1, int flywheel_port_2, char pneumatic_port)
    : flywheel_1_(flywheel_port_1)
    , flywheel_2_(flywheel_port_2)
    , pneumatic_(pneumatic_port, true) 
{
    flywheel_1_.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    flywheel_2_.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

void Intake::Spin() {
    flywheel_1_.move(FORWARD);
    flywheel_2_.move(FORWARD);
}

void Intake::Reverse() {
    flywheel_1_.move(REVERSE);
    flywheel_2_.move(REVERSE);
}

void Intake::Stop() {
    flywheel_1_.move(OFF);
    flywheel_2_.move(OFF);
}

void Intake::Retract() {
    pneumatic_.retract();
}

void Intake::Extend() {
    pneumatic_.extend();
}
