#include "Conveyer.hpp"

Conveyer::Conveyer(int upper_belt_port, int lower_rot_port)
    : u_motor_(upper_belt_port), l_motor_(lower_rot_port) {}

// Run only the upper belt forward
void Conveyer::upper_forward() {
    u_motor_.move(75);
}

// Run only the lower roller forward
void Conveyer::lower_forward() {
    l_motor_.move(75);
}

// Run upper belt reverse
void Conveyer::upper_reverse() {
    u_motor_.move(-75);
}

// Run lower roller reverse
void Conveyer::lower_reverse() {
    l_motor_.move(-75);
}

// Stop just the upper motor
void Conveyer::upper_brake() {
    u_motor_.brake();
}

// Stop just the lower motora
void Conveyer::lower_brake() {
    l_motor_.brake();
}
