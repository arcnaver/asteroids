/***********************************************************************
 * Source File:
 *    FlyingObject
 *
 * Summary:
 *    contains definitions of the flyingObject class
 ************************************************************************/

#include "flyingObject.h"

 /******************************************
  * FlyingObject : advance()
  * sets up points
  *****************************************/
void FlyingObject::advance()
{
   point.setX(point.getX() + velocity.getDx());
   point.setY(point.getY() + velocity.getDy());

   if (this->point.getX() >= 200 || this->point.getX() <= -200)
   {
      this->point.setX(point.getX() * -1);
   }
   if (this->point.getY() >= 200 || this->point.getY() <= -200)
   {
      this->point.setY(point.getY() * -1);
   }
}


