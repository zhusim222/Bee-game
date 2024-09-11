// Obstacle.h
#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "Subject.h"
#include <vector>
#include "Observer.h"

class Obstacle : public Subject {
public:
    Obstacle(float x, float y);
    float get_x() { return x; }
    float get_y() { return y; }
    float get_width() { return width; }
    float get_height() { return height; }
    void update();
    void draw();
    void attach(class Observer* observer) ;
    void detach(class Observer* observer) ;
    void notify(class Observer* observer) ;
    

private:
    float x, y, width, height;
    std::vector<Observer*> observers;
};

#endif  // OBSTACLE_H