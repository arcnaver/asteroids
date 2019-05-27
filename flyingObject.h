/*****************************************
 * FLYING OBJECT
 * This class will have all of the FLYING OBJECT
 * functionality.
 *****************************************/
#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H

#include "point.h"
#include "velocity.h"



class FlyingObject
{
protected:
   // Private variables

   bool alive;
   Point point;
   Velocity velocity;


public:

   // Constructor
   FlyingObject() {}
   virtual ~FlyingObject() { }


   Point          getPoint() const { return point; }
   Velocity getVelocity() const { return velocity; }

   bool            isAlive() const { return alive; }

   void setPoint(const Point & point) { this->point = point; }
   void setVelocity(const Velocity & velocity) { this->velocity = velocity; }
   void kill() { alive = false; }

   

   virtual void advance();
   //virtual void draw() = 0;
   
   
};

#endif
