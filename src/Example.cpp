#include "Example.hpp"

//Sets the first motor to the port
Example::Example(int port) : m_Motor(port) {
    //Prefer constructor initializer list (CLL)
    //More vairbales: m_A(), m_B(), m_C()
    
    //CLL is equivalent to:
    //this->m_Motor(port);

    this->m_Motor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

//Checks the value of reverse then assigns a speed
void Example::spin(Example::SPEED_SETTING speed, bool reverse) {
    //Ternary operator
    speed = (reverse) ? -speed : speed;
    this->m_Motor.move(speed);
}

//Calls spin with speed 0
void Example::stop() {
    this->spin(0);
}