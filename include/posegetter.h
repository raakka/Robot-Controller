#pragma once 
//this is where we can receive our input for our controller
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <frc/Encoder.h>

/*
general notes...
radians/inches/ft are the standard units this program uses
;)
*/


class posegetter{

private:
//empty

public:
//not empty
posegetter();

void initposegetter(double startingx, double startingy, double startingphi);
void voodoomagic();
double calculatedx();
double calculatedy();
double calculatedphi();

//these explain themselves...
double getcurrentx();
double getcurrenty();
double getcurrentphi();

//I'm keeping these as a safety
void setx(double somex);
void sety(double somey);
void setphi(double somephi);

//vars
double lrate;
double rrate;
double wheelbase;
double wheelrad; //this can probably be an int but im using a double here for flexibility
double currentx;
double currenty;
double initx;
double inity;
double initphi;
double phi;
double dphi;
double dx;
double dy; 

frc::Encoder * r_encoder;
frc::Encoder * l_encoder;
};