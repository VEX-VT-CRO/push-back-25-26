#include "main.h"
#include "Drivetrain.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);

// Motor ports 
constexpr int FRONT_LEFT_PORT         = 2;
constexpr int MIDDLE_FRONT_LEFT_PORT  = 3;
constexpr int MIDDLE_BACK_LEFT_PORT   = 4;
constexpr int BACK_LEFT_PORT          = 5;

constexpr int FRONT_RIGHT_PORT        = 9;
constexpr int MIDDLE_FRONT_RIGHT_PORT = 8;
constexpr int MIDDLE_BACK_RIGHT_PORT  = 7;
constexpr int BACK_RIGHT_PORT         = 6;

Drivetrain drive(
    FRONT_LEFT_PORT, MIDDLE_FRONT_LEFT_PORT, MIDDLE_BACK_LEFT_PORT, BACK_LEFT_PORT,
    FRONT_RIGHT_PORT, MIDDLE_FRONT_RIGHT_PORT, MIDDLE_BACK_RIGHT_PORT, BACK_RIGHT_PORT,
    pros::E_MOTOR_BRAKE_BRAKE
);






