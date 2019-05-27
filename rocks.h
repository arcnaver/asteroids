#ifndef rocks_h
#define rocks_h

#include "flyingObject.h"


#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#define BIG_ROCK_SPEED 1
#define MEDIUM_ROCK_SPEED 1


// Define the following classes here:
//   Rock
class Rocks : public FlyingObject
{
private:

public:
   Rocks(const Point &point) 
   {
      alive = true;
      setPoint(point);
   }

   virtual void draw() {};
   
   
   virtual void kill() { alive = false; }
   virtual int hit() { return 1;  };
   void wrap(Point point);
   virtual int getRadius() {return 16;};
   virtual int getRockType() {return 0;}
};

//   BigRock
class BigRock : public Rocks
{
private:
   int rotation = 0;
public:
   BigRock(const Point & point);
   
   virtual void draw();
   virtual void kill() { alive = false; }
   virtual int getRadius() { return BIG_ROCK_SIZE; }
   virtual int getRockType() { return 1; }
   virtual int hit();
};

//   MediumRock
class MediumRock : public Rocks
{
private:
   int rotation = 0;
public:
   MediumRock(const Point & point);
   virtual void draw();
   virtual void kill() { alive = false; }
   virtual int getRockType() { return 2; }
   virtual int getRadius() { return MEDIUM_ROCK_SIZE; }
   virtual int hit();
};

//   SmallRock
class SmallRock : public Rocks
{
private:
   int rotation = 0;
public:
   SmallRock(const Point & point);
   virtual void draw();
   virtual void kill() { alive = false; }
   virtual int getRockType() { return 3; }
   virtual int getRadius() { return SMALL_ROCK_SIZE; }
   virtual int hit();
};


#endif /* rocks_h */
