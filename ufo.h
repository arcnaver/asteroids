#ifndef ufo_h
#define ufo_h

#include "flyingObject.h"
#include "point.h"
#include "velocity.h"



// Shane Purcella's suggestion
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define UFO_SIZE 10
#define UFO_POINTS 5

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#define ANGLE_MAX 359
#define ANGLE_MIN 0
#define ANGLE_START 45

class Ufo : public FlyingObject
{
private:
   
   Point point;
   Velocity velocity;
   
   bool alive;
   int offset = 90;
   int angle = 90;
   int count = 0;
   
   float x = velocity.getDx();
   float y = velocity.getDy();
public:

   Ufo() : point(-199, 165), alive(true) {}
   Ufo(const Point point)
   {

   }
   ~Ufo() {}

   bool isAlive() const { return alive; }

   virtual void advance();
   virtual void draw();
   virtual void kill() { alive = false; }

   Point getPoint()        const { return point; }
   Velocity getVelocity()  const { return velocity; }
   

   void setAlive() { this->alive = true; }
   void rotateLeft();
   void rotateRight();
   void engageEngine();

   void wrap(Point point);

   int getShipSize() const { return UFO_SIZE; }
   int getAngle() const { return angle; }
};

#endif /* ufo_h */
