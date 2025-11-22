#ifndef BRIDGE_HPP_
#define BRIDGE_HPP_

#include "pros/serial.hpp"

#define BAUDRATE 115200 // Baudrate for serial communication

class Bridge {
    // Enums for command type
    enum COMMAND_TYPE {DRIVE = 0, STOP = 1};

    public:
        // Constructs a new bridge object
        // raspbery_pi_port : the port for the raspberry py
        // BAUDRATE : the baudrate to use for communication
        Bridge(int raspberry_pi_port);

        // Proccesses any inputs
        void ProcessInput();
    
    private:
        pros::Serial serial_;
};

#endif // BRIDGE_HPP_