//
//  Rocket class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef ROCKET_H
#define ROCKET_H

#include "Object.h"

class Rocket: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Rocket(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
   //double normalPlane(double *p1,double *p2, double *p3,double *norm);
};

#endif

