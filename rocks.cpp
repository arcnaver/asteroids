#include "rocks.h"
#include "uiDraw.h"

// Shane Purcella's suggestion
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;
// Put your Rock methods here
/****************************
*  ROCKS
*****************************
*****************************/
void Rocks::wrap(Point point)
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

/****************************
*  BigRock
*****************************/
BigRock::BigRock(const Point & point) : Rocks(point)
{
   float x = random(0, 360);
   float y = random(0, 360);
  
   float dx = BIG_ROCK_SPEED * (-cos(M_PI / 180.0 * x));
   float dy = BIG_ROCK_SPEED * (sin(M_PI / 180.0 * y));

   Velocity newVelocity;
   newVelocity.setDx(dx);
   newVelocity.setDy(dy);
   
   setVelocity(newVelocity);
}

void BigRock::draw()
{
   rotation += BIG_ROCK_SPIN;
   drawLargeAsteroid(point, rotation);
   
}

int BigRock::hit()
{
   return 1;
}


/****************************
*  MediumRock
*****************************/
MediumRock::MediumRock(const Point & point) : Rocks(point)
{
   float x = random(0, 360);
   float y = random(0, 360);

   float dx = BIG_ROCK_SPEED * (-cos(M_PI / 180.0 * x));
   float dy = BIG_ROCK_SPEED * (sin(M_PI / 180.0 * y));

   Velocity newVelocity;
   newVelocity.setDx(dx);
   newVelocity.setDy(dy);

   setVelocity(newVelocity);
}
void MediumRock::draw()
{
   rotation += MEDIUM_ROCK_SPIN;
   drawMediumAsteroid(point, rotation);
}

int MediumRock::hit()
{
   return 0;
}



/****************************
*  SmallRock
*****************************/
SmallRock::SmallRock(const Point & point) : Rocks(point)
{
   float x = random(0, 360);
   float y = random(0, 360);

   float dx = BIG_ROCK_SPEED * (-cos(M_PI / 180.0 * x));
   float dy = BIG_ROCK_SPEED * (sin(M_PI / 180.0 * y));

   Velocity newVelocity;
   newVelocity.setDx(dx);
   newVelocity.setDy(dy);

   setVelocity(newVelocity);
}
void SmallRock::draw()
{
   rotation += SMALL_ROCK_SPIN;
   drawSmallAsteroid(point, rotation);
}

int SmallRock::hit()
{
   return 0;
}

