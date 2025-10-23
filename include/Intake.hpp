#ifndef INTAKE_HPP__
#define INTAKE_HPP__

#include "pros/motors.hpp"
#include "pros/adi.hpp"

// Intake controls the initial expansion of the collection mechanism as 
// well as whether or not the flywheel (s) spin
// 
class Intake {
    // Change value based on testing. Speeds for flywheel on or off
    enum SPEED_SETTING {OFF = 0, ON = 100};

    public:
        // Constructs a new Intake object
        // flywheel_port : the port for the flywheel
        // pneumatic_port : the port the pneumatic
        Intake(int flywheel_port, char pneumatic_port);
        
        // Spins the flywheel to intake blocks
        void Spin();

        // Stops the flywheel to allow pushing blocks
        void Stop();

        // Retract the pneumatic to expand the robot
        void Retract();

        // Extend the pneumatic so intake can be collapsed
        void Extend();

    private:
        // The flywheel
        pros::Motor flywheel_;

        // The pneumatic
        pros::adi::Pneumatics pneumatic_;
};

#endif //INTAKE_HPP__