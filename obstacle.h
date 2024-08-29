#ifndef OBSTACLE_H
#define OBSTACLE_H

/**
 * Represents an obstacle in the game, such as a box.
 */
class Obstacle {
public:
    /**
     * x position of the obstacle.
     */
    float x;

    /**
     * y position of the obstacle.
     */
    float y;

    /**
     * Width of the obstacle.
     */
    float width;

    /**
     * Height of the obstacle.
     */
    float height;

    /**
     * Type of obstacle (e.g., bee, butterfly).
     */
    int type;

    /**
     * Speed of the obstacle.
     */
    float speed;

    /**
     * Constructor for Obstacle class.
     * param x Initial x position.
     * param y Initial y position.
     * param width Initial width.
     * param height Initial height.
     * param type Initial type.
     * param speed Initial speed.
     */
    Obstacle(float x, float y, float width, float height, int type, float speed);

    /**
     * Updates the obstacle's position based on its speed.
     */
    void update();

    /**
     * Draws the obstacle on the screen.
     */
    void draw();
};

#endif  // OBSTACLE_H