#include "ColorSorting.hpp"


ColorSorting::ColorSorting(int port, const std::uint8_t o_port, int team) : c_motor_(port), color_optical_(o_port) {
    //intializes first motor on port
    //intializes first sensor on optical port
}

//take vex sensor data and compare it against the team value
//if the sensor data reads high for red then assign value 1 to compareVal; Otherwise blue which is assigned 0
//.accept and .reject depend on .compare
int ColorSorting::compare(int team) {
    redVal = color_optical_.get_rgb().red;
    blueVal = color_optical_.get_rgb().blue;
    if (redVal > 200)
        compareVal = 1;
    else
        compareVal = 0;
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
    if (compare(team) == team){
        accept();
    }
    else {
        reject();
    }

}