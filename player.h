#ifndef PLAYER_H
#define PLAYER_H

class Player { // Add the class keyword here
public:
    /**
     * Constructor for Player class.
     * @param x Initial x position.
     * @param y Initial y position.
     * @param speed Player movement speed.
     */
    Player(float x, float y, float speed);

    /**
     * Move player right.
     */
    void move_right();

    /**
     * Move player left.
     */
    void move_left();

    /**
     * Get player x position.
     * @return x position.
     */
    float get_x();

    /**
     * Get player y position.
     * @return y position.
     */
    float get_y();

private:
    float x, y; // player position
    float speed; // player movement speed
};

#endif  // PLAYER_H