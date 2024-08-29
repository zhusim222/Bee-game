// import
#include "splashkit.h"
#include "globals.h" // <- added this import
//#include <graphics.h>
#include <cstdlib>
#include "player.h"
#include "obstacle.h"

bitmap background = bitmap_named("images/Background.jpg");
bitmap bee = bitmap_named("images/Bee.png");
bitmap box = bitmap_named("images/box.png");
float player_posx = 480.0f;
float player_posy = 550.0f;
int RIGHT_BOUNDARY = 1020;
int LEFT_BOUNDARY = 0;

int main()
{
    open_window("BeeFall", 1280, 960); //named window beefall and window size
    hide_mouse(); // hide mouse while cursor is over game window
    Player player(480.0f, 550.0f, 10.0f); // initialize player
    Obstacle boxObstacle(640, 0, 100, 100, 0, 2); // x, y, width, height, type, speed
    
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
            Obstacle newObstacle(spawn_x, 0, 100, 100, 0, 2);
            obstacles.push_back(newObstacle);
        }
                

        //redrawing the bitmap after every clear background and bee
        draw_bitmap(background, 0 , 0 , option_to_screen());
        draw_bitmap(bee, player.get_x(), player.get_y(), option_to_screen());
        // Update and draw obstacles
        for (Obstacle& obstacle : obstacles) {
            obstacle.update();
            obstacle.draw();
        }
        refresh_screen(60);
    }
}
