#include "Outtake.hpp"

// Running flywheel (s) "spin"
// Reversing flywheel (s) "reverse"

// Sets flywheel and pneumatic to the correct ports
// Sets the brake mode of the motor to hold (quicker turnaround to be able to push?)
Outtake::Outtake(int flywheel_port) 
    : flywheel_(flywheel_port) {
    this->flywheel_.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}

// Sets the flywheel speed to the value of ON
void Outtake::Spin() {
    this->flywheel_.move(FORWARD);
}

void Outtake::Reverse() {
    this->flywheel_.move(REVERSE);
}

// Sets flywheel speed to OFF (zero) to stop the spin
void Outtake::Stop() {
    this->flywheel_.move(OFF);
}