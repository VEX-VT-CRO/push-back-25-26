#ifndef _CONVEYER_
#define _CONVEYER_

#include "pros/motors.hpp"

class Conveyer {
    public:
        Conveyer(int upper_belt_port,  int lower_rot_port);

        void forward();

        void reverse();

        void brake();

    private:
        pros::Motor u_motor_;
        pros::Motor l_motor_;
};




#endif