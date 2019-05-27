#include "ship.h"
#include "uiDraw.h"

// Put your ship methods here
/***************************
*  SHIP
****************************/
void Ship::advance()
{
   
   point.addX(velocity.getDx()); // get the direction from velocity
   point.addY(velocity.getDy()); // get the direction from velocity
  
   wrap(point);
      
}

void Ship::draw()
{
   
   if (isAlive())
   {
      // draw ship
      drawShip(point, /*int rotation*/ angle - offset, /*bool thrust*/ thrust);
   }
   
}

/******************
* SHIP MOTION
*******************/
void Ship::rotateLeft()
{
   angle += ROTATE_AMOUNT;
}

void Ship::rotateRight()
{
   angle -= ROTATE_AMOUNT;
}

void Ship::engageEngine()
{
  
   thrust = true;
   
   
   velocity.setDx(cos(M_PI / 180.0 * angle) * THRUST_AMOUNT);  
   velocity.setDy(sin(M_PI / 180.0 * angle) * THRUST_AMOUNT);

   velocity.setDx(x += velocity.getDx());
   velocity.setDy(y += velocity.getDy());
    
   
}

/**********************************
* WRAP
************************************/
void Ship::wrap(Point point)
{
   if (this->point.getX() >= 200 || this->point.getX() <= -200)
   {
      this->point.setX(point.getX() * -1);
   }
   if (this->point.getY() >= 200 || this->point.getY() <= -200)
   {
      this->point.setY(point.getY() * -1);
   }
}