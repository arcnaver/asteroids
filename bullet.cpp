/***********************************************************************
 * Source File:
 *    bullet.cpp
 * Author:
 *    Adam Tipton
 * Summary:
 *    Everything we need to know about a bullet
 ************************************************************************/

#include "bullet.h"
#include "uiDraw.h"


 /*********************************************
  * DRAW
  * Draws the bullet
  *********************************************/
void Bullet::draw()
{
   if (isAlive())
   {
      drawDot(point);
   }
   
}

/*********************************************
 * ADVANCE
 * A single position.
 *********************************************/
void Bullet::advance()
{
   if (count != 40)
   {
      point.addX(velocity.getDx());
      point.addY(velocity.getDy());

      wrap(point);
      count++;
   }
   else if (count = 40)
   {
      kill();
      count = 0;
   }
   
}

/*********************************************
 * FIRE
 * A single position.
 *********************************************/
void Bullet::fire(Point point, float angle, Velocity vel)
{
   
   this->point = point;
   //this->velocity = vel;

   // Declare some floats to pass dx and dy info
   float x = vel.getDx();
   float y = vel.getDy();

   // Reused from Skeet - sets up bullet speed and direction
   velocity.setDx(cos(M_PI / 180.0 * angle) * BULLET_SPEED);
   velocity.setDy(sin(M_PI / 180.0 * angle) * BULLET_SPEED);

   // call the same functions as above but pass into it the x/y += to DX/DY
   // will make the bullets come out of the ship at high speeds. 
   velocity.setDx(x += velocity.getDx());
   velocity.setDy(y += velocity.getDy());
   //setVelocity(vel);
     
}

/*******************************************
*  WRAP
********************************************/
void Bullet::wrap(Point point)
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