#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player(float x, float y, float speed);
    void move_right();
    void move_left();
    float get_x();
    float get_y();

private:
    float x, y; // player position
    float speed; // player movement speed
};

#endif  // PLAYER_H