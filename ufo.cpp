#include "ufo.h"
#include "uiDraw.h"

// Put your ufo methods here
/***************************
*  UFO
****************************/
void Ufo::advance()
{
   if (isAlive())
   {
      point.addX(velocity.getDx()); // get the direction from velocity
      point.addY(velocity.getDy()); // get the direction from velocity
      engageEngine();

   }
   

   wrap(point);

}

void Ufo::draw()
{
   
   if (isAlive())
   {
      drawPolygon(point, UFO_SIZE, UFO_POINTS, 0);
   }

}

/******************
* UFO MOTION
*******************/

void Ufo::engageEngine()
{
   velocity.setDx(3);
   velocity.setDy(0);
   
}

/**********************************
* WRAP
************************************/
void Ufo::wrap(Point point)
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