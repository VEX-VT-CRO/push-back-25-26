#include "ColorSorting.hpp"
#include "pros/llemu.hpp"


ColorSorting::ColorSorting(int port, const std::uint8_t o_port, int team) : c_motor_(port), color_optical_(o_port), team(team) {
    //intializes first motor on port
    //intializes first sensor on optical port
}

//take vex sensor data and compare it against the team value
//if the sensor data reads high for red then assign value 1 to compareVal; Otherwise blue which is assigned 0
//.accept and .reject depend on .compare
int ColorSorting::compare(int team) {
    redVal = color_optical_.get_rgb().red;
    blueVal = color_optical_.get_rgb().blue;
    // pros::lcd::print(3, "Red Val is: %d", redVal);
    // pros::lcd::print(4, "Ball Color is: %d", ballColor);
    // pros::lcd::print(5, "Team is: %d", team);
    if (redVal > 400)
        ballColor = static_cast<int>(TEAM_COLOR::RED);
    else
        ballColor = static_cast<int>(TEAM_COLOR::BLUE);
    compareVal = (ballColor == team) ? 1 : 0;
    return compareVal;
}

//function to work withing .run
//assigns motor move value
void ColorSorting::accept() {
    c_motor_.move(100);
}

//function to work withing .run
//assigns motor move value that is opposite from .accept
void ColorSorting::reject() {
    c_motor_.move(-100);
}

//allows to run all three functions within color sorting to get one output on the sorting motor
void ColorSorting::run() {
    if (compare(team)){
        accept();
    }
    else {
        reject();
    }

}