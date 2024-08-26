#include "player.h"

Player::Player(float x, float y, float speed) {
    this->x = x;
    this->y = y;
    this->speed = speed;
}

void Player::move_right() {
    
    x += speed;
    
}

void Player::move_left() {
    
    x -= speed;
    
}

float Player::get_x() {
    return x;
}

float Player::get_y() {
    return y;
}