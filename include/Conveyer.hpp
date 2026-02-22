#ifndef _CONVEYER_
#define _CONVEYER_

#include "pros/motors.hpp"

class Conveyer {
public:
    Conveyer(int upper_belt_port, int lower_rot_port);

    // Independent controls:
    void upper_forward();
    void upper_reverse();
    void upper_brake();

    void lower_forward();
    void lower_reverse();
    void lower_brake();

private:
    pros::Motor u_motor_;
    pros::Motor l_motor_;
};

#endif
