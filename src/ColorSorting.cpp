#include "ColorSorting.hpp"


ColorSorting::ColorSorting(int port, int team) : c_motor(port){
    //intializes first motor on port
}

//eventually will take camera data and compare it against the team value
//.accept and .reject depend on .compare
//could potentially be another class depending on how big the function gets
void ColorSorting::compare(int team){
    compareVal = (ballColor == team) ? 1 : 0;
    std::cout << compareVal;
}

//function to work withing .run
//assigns motor move value
void ColorSorting::accept(){
    c_motor.move(100);
}

//function to work withing .run
//assigns motor move value that is opposite from .accept
void ColorSorting::reject(){
    c_motor.move(-100);
}

//allows to run all three functions within color sorting to get one output on the sorting motor
void ColorSorting::run(){
    compare(team);
        if (compareVal == 1){
            accept();
        }
        else {
            reject();
        }

}