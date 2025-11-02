#ifndef __COLORSORTING__
#define __COLORSORTING__

#include "motors.hpp"

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

        //idk what im doing with this yet
        enum class TEAM_COLOR 
        {
           BLUE = -1,
           RED = 1, 
        };

        //Constructs a new Sorting Method
        //port: motor port for sorting motor
        //team: color of team as either -1 or 1
        ColorSorting(int port, int team);
        
        //runs the sorting function
        void run();

        //compares team int value to color value found by camera
        //team: color of team as either -1 or 1
        void compare(int team); 

        //Based on compare spins the motor to feed into track
        void accept();

        //Based on compare spins motor to discharge ball
        void reject();

    private:
        //Sorting Motor
        pros::Motor c_motor_;   
};



#endif