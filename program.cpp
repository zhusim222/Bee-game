// import
#include "splashkit.h"
#include "globals.h" // <- added this import
//#include <graphics.h>
#include <cstdlib>
#include "player.h"
#include "obstacle.h"
#include "Observer.h"
#include "Subject.h"
#include <iostream>
//skm g++ program.cpp player.cpp Observer.cpp Subject.cpp obstacle.cpp -o game.exe

bitmap background = bitmap_named("images/Background.jpg");
bitmap bee = bitmap_named("images/Bee.png");
bitmap box = bitmap_named("images/box.png");
float player_posx = 480.0f;
float player_posy = 550.0f;
int RIGHT_BOUNDARY = 1020;
int LEFT_BOUNDARY = 0;
int GRAVITY = 3;

template <typename T, typename U>
bool is_colliding(T& obj1, U& obj2) {
    float x1 = obj1.get_x();
    float y1 = obj1.get_y();
    float w1 = obj1.get_width();
    float h1 = obj1.get_height();

    float x2 = obj2.get_x();
    float y2 = obj2.get_y();
    float w2 = obj2.get_width();
    float h2 = obj2.get_height();

    // Check for collision
    return (x1 < x2 + w2 &&
            x1 + w1 > x2 &&
            y1 < y2 + h2 &&
            y1 + h1 > y2);
}

// Function to handle collision between two objects
template <typename T, typename U>
void handle_collision(T& obj1, U& obj2) {
    if (is_colliding(obj1, obj2)) {
        if (!obj2.get_collision()) { // Collision started
            obj2.notify(&obj1);
            obj2.set_collision(true);
        }
    } else {
        if (obj2.get_collision()) { // Collision ended
            obj2.set_collision(false);
            // Optional: trigger a notification or state change when the collision ends
            std::cout << "collision ends" << std::endl;
        }
    }
}


int main()
{
    open_window("BeeFall", 1280, 960); //named window beefall and window size
    hide_mouse(); // hide mouse while cursor is over game window
    Player player(480.0f, 550.0f, 10.0f); // initialize player
    std::vector<Obstacle> obstacles; // list of obstacle

    // Spawn obstacles at a rate of 1 per second
    int spawn_interval = 60; // 60 frames per second
    int spawn_timer = 0;

    while (!quit_requested())
    {
        process_events();
        clear_screen();
        
         if (key_down(RIGHT_KEY) && player.get_x() <= RIGHT_BOUNDARY) {
            player.move_right();
        }
        if (key_down(LEFT_KEY) && player.get_x() >= LEFT_BOUNDARY) {
            player.move_left();
        }
        

        // Spawn obstacle at a random x-coordinate
        spawn_timer++;
        if (spawn_timer >= spawn_interval)
        {
            spawn_timer = 0;
            int spawn_x = rand() % RIGHT_BOUNDARY; // Random x-coordinate between 0 and RIGHT_BOUNDARY
            Obstacle newObstacle(spawn_x, 0,2);
            obstacles.push_back(newObstacle);
            newObstacle.attach(&player); // Attach player observer to new obstacle
        }
                

        //redrawing the bitmap after every clear background and bee
        draw_bitmap(background, 0 , 0 , option_to_screen());
        draw_bitmap(bee, player.get_x(), player.get_y(), option_to_screen());

        // Update and draw obstacles
        for (Obstacle& obstacle : obstacles) {
            obstacle.update();
            obstacle.draw();
            handle_collision(player, obstacle);
        }
        refresh_screen(60);
    }
}
