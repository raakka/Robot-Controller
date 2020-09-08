#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <array>

class controller{
    private:
    //wow its empty here...

    public:

    controller();

    struct point{
        double xcord;
        double ycord;
    };

    point pt1; 
    point pt2;
    point pt3;
    point pt4;
    point pt5;
    point targetpoint;

    point waypoints[5]; //list were not working so im using arrays to do -> fix this horrible design
    double l;
    double r;
    double leftvel;
    double rightvel;
    double targetphi;
    double phierr;
    double vel;
    double K = 1;
    int whatpoint = 0;

    void controllerinit(double wheelbase, double wheelrad, double desiredvel, double constant);
    void controllerloop(double currentphi, double currentx, double currenty);
    double outputlvel(double dphi);
    double outputrvel(double dphi);
    double outputphierr();
};
