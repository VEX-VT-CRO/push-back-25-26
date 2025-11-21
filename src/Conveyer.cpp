#include "Conveyer.hpp"

Conveyer::Conveyer(int upper_belt_port,  int lower_rot_port) : u_motor_(upper_belt_port), l_motor_(lower_rot_port) {

};

void Conveyer::forward() {
    u_motor_.move(100);
    l_motor_.move(100);
}
 void Conveyer::reverse() {
    u_motor_.move(-100);
    l_motor_.move(-100);
 }

 void Conveyer::brake() {
    u_motor_.brake();
    l_motor_.brake();
 }
