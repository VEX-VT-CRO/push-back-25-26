#include "Bridge.hpp"

// Sets the serial connection to the raspberry pi to right port
// Sets the communication baudrate to the correct value
// Clears the internal input and ouput FIFO buffers
Bridge::Bridge(int raspberry_pi_port) : serial_(raspberry_pi_port, BAUDRATE) {
    serial_.flush();
}

// Control word: 14 bytes
// 1st byte: command
// 2nd-13th bytes: parameters
// 14th byte: command end
void Bridge::ProcessInput() { 
    // If there's not a full command to read, don't do anything
    if (serial_.get_read_avail() < 14) {
        return;
    }

    // Read a command word from the input buffer
    std::uint8_t command[14];
    serial_.read(command, 14);

    // Use the command type to determine next action
    int command_type = command[0];
    switch (command_type) {
        case DRIVE:
            break;
        case STOP:
            break;
        default:
            break;
    }
}