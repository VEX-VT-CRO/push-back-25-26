#ifndef __COLORSORTING__
#define __COLORSORTING__

#include "pros/motors.hpp"
#include "pros/optical.hpp"

//Class looks at color of ball robot trys to pick and compares it to the color of the team the robot is assigned
//expects motor port for the sorting motor; expects a value for the team color
class ColorSorting {
    public: 
        //Used in .compare as a true or false--May change to boolean
        int compareVal;
        //assigned a number based on ball color
        int ballColor;
        //either a 1 or -1 depending on team color
        int team; 
        //red value pulls from the color vex sensor
        int redVal;
        //blue valuem pulls from the color vex sensor
        int blueVal;

        //idk what im doing with this yet
        enum class TEAM_COLOR 
        {
           BLUE = 0,
           RED = 1, 
        };

        //Constructs a new Sorting Method
        //port: motor port for sorting motor
        //port_o: port for vex sensor
        //team: color of team as either 0 for Blue and 1 for Red
        ColorSorting(int port, const std::uint8_t port_o, int team);
        
        //runs the sorting function
        void run();

        //compares team int value to color value found by camera
        //team: color of team as either -1 or 1
        int compare(int team); 

        //Based on compare spins the motor to feed into track
        void accept();

        //Based on compare spins motor to discharge ball
        void reject();

    private:
        //Sorting Motor
        pros::Motor c_motor_;
        //sorting sensor
        pros::Optical color_optical_;   
};



#endif