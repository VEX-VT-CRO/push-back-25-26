#include "Intake.hpp"

// Running flywheel (s) "spin"
// Pneumatic that releases elastic to expand catching system "release"

// Sets flywheel and pneumatic to the correct ports
// Pneumatic starts extended
// Sets the brake mode of the motor to hold (quicker turnaround to be able to push?)
Intake::Intake(int flywheel_port, char pneumatic_port) 
    : flywheel_(flywheel_port), pneumatic_(pneumatic_port, true) {
    this->flywheel_.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

// Sets the flywheel speed to the value of ON
void Intake::Spin() {
    this->flywheel_.move(ON);
}

// Sets flywheel speed to OFF (zero) to stop the spin
void Intake::Stop() {
    this->flywheel_.move(OFF);
}

// Retracts the pneumatic to allow the intake mechanism to expand
void Intake::Retract() {
    this->pneumatic_.retract();
}

// Extends the pneumatic to allow for the intake mechanism to be collapsed
void Intake::Extend() {
    this->pneumatic_.extend();
}