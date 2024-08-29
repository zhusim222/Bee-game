#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle {
public:
    float x, y; // position
    float width, height; // size
    int type; // type of obstacle (e.g., bee, butterfly)
    float speed; // speed of obstacle

    Obstacle(float x, float y, float width, float height, int type, float speed);
    void update();
    void draw();
};

#endif  // OBSTACLE_H