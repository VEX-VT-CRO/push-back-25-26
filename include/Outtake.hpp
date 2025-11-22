#ifndef OUTTAKE_HPP_
#define OUTTAKE_HPP_

#include "pros/motors.hpp"

class Outtake {
    // Change value based on testing. Speeds for flywheel off, forward, or reverse
    enum SPEED_SETTING {OFF = 0, FORWARD = 100, REVERSE = -100};

    public:
        // Constructs a new Outtake object
        // flywheel_port : the port for the flywheel
        Outtake(int flywheel_port);
        
        // Spins the flywheel to intake blocks
        void Spin();

        // Reverses the flywheel
        void Reverse();

        // Stops the flywheel to allow pushing blocks
        void Stop();

    private:
        // The flywheel
        pros::Motor flywheel_;
};

#endif //OUTTAKE_HPP_