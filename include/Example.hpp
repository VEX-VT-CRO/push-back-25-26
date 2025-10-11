#ifndef __EXAMPLE_HPP__
#define __EXAMPLE_HPP__

#include "motors.hpp"

//Example is a flywheel controller
//Example expects one motor that drive the flywheel
class Example
{
    public:
        enum class SPEED_SETTING
        {
            STOP = 0,
            SLOW = 50,
            MEDIUM = 100,
            FAST = 127
        };

        //Default flywheel speed
        static constexpr SPEED_SETTING FLYWHEEL_SPEED = SPEED_SETTING::FAST;

        //Contructs a new Example
        // port: the port for the flywheel
        Example(int port);

        //Spins the flywheel at a certain value
        // speed: speed of motor (-127 to 127)
        // reverse: when true, spins backwards
        void spin(SPEED_SETTING speed = FLYWHEEL_SPEED, bool reverse = false);

        //Stops the flywheel
        void stop();

    private:
        //The only flywheel
        pros::Motor m_Motor;
};

#endif