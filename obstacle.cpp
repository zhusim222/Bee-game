#include "obstacle.h"
#include "globals.h" 
#include "splashkit.h"

Obstacle::Obstacle(float x, float y, float width, float height, int type, float speed) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->type = type;
    this->speed = speed;
}

void Obstacle::update() {
    y += speed; // move obstacle down
}

void Obstacle::draw() {
   draw_bitmap(box, x, y, option_to_screen());
}