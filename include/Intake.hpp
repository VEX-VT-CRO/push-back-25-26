#ifndef INTAKE_HPP_
#define INTAKE_HPP_

#include "pros/motors.hpp"
#include "pros/adi.hpp"

// Intake controls the initial expansion of the collection mechanism as 
// well as whether or not the flywheel (s) spin
// Intake expects one motor that drives the flywheel and one solenoid
// which drives the expansion / collapse of the assembly
class Intake {
    // Change value based on testing. Speeds for flywheel off, forward, or reverse
    enum SPEED_SETTING {OFF = 0, FORWARD = 100, REVERSE = -100};

    public:
        // Constructs a new Intake object
        // flywheel_port : the port for the flywheel
        // pneumatic_port : the port the pneumatic
        Intake(int flywheel_port, char pneumatic_port);
        
        // Spins the flywheel to intake blocks
        void Spin();

        // Reverses the flywheel
        void Reverse();

        // Stops the flywheel to allow pushing blocks
        void Stop();

        // Retract the pneumatic to expand the robot
        void Retract();

        // Extend the pneumatic so intake can be collapsed
        void Extend();

        // TODO: Add reverse to spin (automatic or manual)

    private:
        // The flywheel
        pros::Motor flywheel_;

        // The pneumatic
        pros::adi::Pneumatics pneumatic_;
};

#endif //INTAKE_HPP_