#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <array>
#include "controller.h"

controller::controller() {}

void controller::controllerinit(double wheelbase, double wheelrad, double desiredvel, double constant) {
    //these are test points lol 
    //when we make the GUI we can make actual ones...    
    pt1 = {23, 34};
    pt2 = {88, 60};
    pt3 = {62, 100};
    pt4 = {120, 130};
    pt5 = {150, 150};
        
    point waypoints[5] = {pt1, pt2, pt3, pt4, pt5};
    l = wheelbase;
    r = wheelrad;
    vel = desiredvel;
    K = constant;
}

void controller::controllerloop(double currentphi, double currentx, double currenty) {
    switch (whatpoint)
    {
    case 0:
        targetpoint = waypoints[whatpoint];
        targetphi = atan((targetpoint.ycord - currenty)/(targetpoint.xcord - currentx));
        phierr = K*(targetphi - currentphi);
        if (currentx == targetpoint.xcord && currenty == targetpoint.ycord){
            whatpoint++;
        }
    case 1:
        targetpoint = waypoints[whatpoint];
        targetphi = atan((targetpoint.ycord - currenty)/(targetpoint.xcord - currentx));
        phierr = K*(targetphi - currentphi);
        if (currentx == targetpoint.xcord && currenty == targetpoint.ycord){
            whatpoint++;
        }
    case 2:
        targetpoint = waypoints[whatpoint];
        targetphi = atan((targetpoint.ycord - currenty)/(targetpoint.xcord - currentx));
        phierr = K*(targetphi - currentphi);
        if (currentx == targetpoint.xcord && currenty == targetpoint.ycord){
            whatpoint++;
        }
    case 3:
        targetpoint = waypoints[whatpoint];
        targetphi = atan((targetpoint.ycord - currenty)/(targetpoint.xcord - currentx));
        phierr = K*(targetphi - currentphi);
        if (currentx == targetpoint.xcord && currenty == targetpoint.ycord){
            whatpoint++;
        }
    case 4:
        targetpoint = waypoints[whatpoint];
        targetphi = atan((targetpoint.ycord - currenty)/(targetpoint.xcord - currentx));
        phierr = K*(targetphi - currentphi);
        if (currentx == targetpoint.xcord && currenty == targetpoint.ycord){
            whatpoint++;
        }
    case 5:
        break;

    default:
        break;
    }
}

double controller::outputphierr() {
    return phierr;
}

//in this case the "dphi" used here is how fast the err in angle between the target and the robots pose is changing
//we can scale dphi by k as done in the above to further tune our control
//a bigger K means that the robot "turns" more agressively
//the right and left velocity being outputted is how fast the wheels on their respective sides should be turning
//you need a pid loop or some other control method to tell the robot to get to those speeds...
double controller::outputlvel(double dphi) { //outputs velocity of left wheel
    leftvel = ((2*vel) - (l*dphi))/(2*r);
    return rightvel;
} 

double controller::outputrvel(double dphi) { //outputs velocity of right wheel
    rightvel = ((2*vel) + (l*dphi))/(2*r);
    return rightvel;
}