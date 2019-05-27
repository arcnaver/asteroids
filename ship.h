#ifndef ship_h
#define ship_h

#include "flyingObject.h"
#include "point.h"
#include "velocity.h"


// Shane Purcella's suggestion
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5

#define ANGLE_MAX 359
#define ANGLE_MIN 0
#define ANGLE_START 45

#define SHIP_SIZE 10

class Ship : public FlyingObject
{
private:
   bool thrust; // needed for draw ship
   Point point;
   Velocity velocity;
   bool alive;
   int offset = 90;
   int angle = 90;
   
   float x = velocity.getDx();
   float y = velocity.getDy();
public:
   
   Ship() : point(0, 0), alive(true) {}
   Ship(const Point point) 
   {

   }
   ~Ship() {}

   bool isAlive() const { return alive; }

   virtual void advance();
   virtual void draw();
   virtual void kill() { alive = false; }

   Point getPoint()        const { return point; }
   Velocity getVelocity()  const { return velocity; }
   void cutEngine() { thrust = false; }

   void setAlive(bool alive) { this->alive = alive; }
   void rotateLeft();
   void rotateRight();
   void engageEngine();

   void wrap(Point point);

   int getShipSize() const { return SHIP_SIZE ; }
   int getAngle() const { return angle; }
};

#endif /* ship_h */
