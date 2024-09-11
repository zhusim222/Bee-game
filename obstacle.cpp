#include "obstacle.h"
#include "globals.h" 
#include "splashkit.h"
#include <algorithm>

Obstacle::Obstacle(float x, float y){
    this->x = x;
    this->y = y;
    this->width = bitmap_width(box);
    this->height = bitmap_height(box);
}

void Obstacle::update(){
    this->y = this->y + GRAVITY;
}

void Obstacle::draw() {
   draw_bitmap(box, x, y, option_to_screen());
}

void Obstacle::attach(Observer* observer) {
    observers.push_back(observer);
}

void Obstacle::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Obstacle::notify(Observer* observer) {
    observer->onCollision(*this); // Call onCollision on the observer, passing this obstacle
}