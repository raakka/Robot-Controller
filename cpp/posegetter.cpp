#include "posegetter.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <frc/Encoder.h>

posegetter::posegetter() {}

// this is a garbage way of setting default values
//to do -> make sure you can just set defaults when the object is constructed
//keep these in case you want to change the values sometime after making the obj
void posegetter::initposegetter(double startingx, double startingy, double startingphi) {
    
    //default to 0, 0, 0
    if (startingphi == NULL){
        initphi = 0.0;
    }
    else{
        initphi = startingphi;
    }

    if (startingy == NULL){
        inity = 0.0;
    }
    else{
        inity = startingy;
    }

    if (startingx == NULL){
        initx = 0.0;
    }
    else{
        initx = startingx;
    }
    
    //encoder junk
    l_encoder = new frc::Encoder(0, 1);
    r_encoder = new frc::Encoder(2, 3);
}

void posegetter::setphi(double somephi) {
    initphi = somephi;
    //this feels so dumb, ed, how can I do this better?
}

void posegetter::setx(double somex) {
    initx = somex;
    //this is definitely bad
}

void posegetter::sety(double somey) {
    inity = somey;
}

//this can probably be updated to be faster because I don't really understand how this processes in the rio
// to do -> make this as fast as possible
void posegetter::voodoomagic(){
    //this basically integrates the dx, dy, dphi for current pose
    currentx = initx + calculatedx();
    currenty = inity + calculatedy();
    phi = initphi + calculatedphi();

}

//these can probably made faster but they are okay for now
//to do -> also make these faster

//STOPPPPPPPP!!!!!!
//this dphi IS NOT RESPECT TO A GOAL
//THIS IS JUST HOW FAST IS IT TURNING
//NOT HOW FAST THE ANGLE ERR CHANGES TO THE GOAL
double posegetter::calculatedphi() {
    dphi = (wheelrad/wheelbase)*(r_encoder->GetRate() - l_encoder->GetRate());
    return dphi;
}

double posegetter::calculatedx() {
    dx = (wheelrad/2)*(l_encoder->GetRate() + r_encoder->GetRate())*(cos(phi));
    return dx;
}

double posegetter::calculatedy() {
    dy = (wheelrad/2)*(l_encoder->GetRate() + r_encoder->GetRate())*(sin(phi));
    return dy;
}

//these aren't so bad... I think?
double posegetter::getcurrentphi() {
    return phi;
}

double posegetter::getcurrentx() {
    return currentx;
}

double posegetter::getcurrenty() {
    return currenty;
}

