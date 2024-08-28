#include "player.h"
#include <splashkit.h>
#include "globals.h"
#include <iostream>

Player::Player(float x, float y, float speed) {
    this->x = x;
    this->y = y;
    this->speed = speed;
    this->width = bitmap_width(bee); // Assuming 'bee' is the bitmap for the player
    this->height = bitmap_height(bee);
}

void Player::move_right() {
    
    x += speed;
}

void Player::move_left() {
    
    x -= speed;
    
}

void Player::onCollision(Obstacle& obstacle) {
    std::cout << "Bee touched the box!" << std::endl;
}