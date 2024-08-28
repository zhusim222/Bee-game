// observer.h
#ifndef OBSERVER_H
#define OBSERVER_H
#include "obstacle.h"

class Obstacle;

class Observer {
public:
    virtual ~Observer() {}
    virtual void onCollision(Obstacle& obstacle);
};

#endif  // OBSERVER_H