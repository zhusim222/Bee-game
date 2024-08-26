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
int RIGHT_BOUNDARY = 880;
int LEFT_BOUNDARY = 140;

int main()
{
    open_window("BeeFall", 1280, 960); //named window beefall and window size
    hide_mouse(); // hide mouse while cursor is over game window
    Player player(480.0f, 550.0f, 10.0f); // initialize player
    Obstacle boxObstacle(640, 0, 100, 100, 0, 2); // x, y, width, height, type, speed
    
    std::vector<Obstacle> obstacles; // list of obstacle

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
       
        
        // remove comment if UP and DOWN is needed to be added
        //if (key_down(UP_KEY))
        //{
        //    player_posy -= 10.0f;
        //}
        //if (key_down(DOWN_KEY))
        //{
        //    player_posy += 10.0f;
        //}

        



        //random stuff need to chuck this under a timer based system. dont forget pause needs to pause timer.
        int spawn_number = (rand() % 2); // either 1 or 2 falling objects
        for (int i = 0; i <= spawn_number; i++)
        {
            int spawn_location = (rand() % 10);
            if (spawn_location < 3)
            {
                //spawn left (30%)
                // Spawn obstacles at random intervals
                if (rand() % 100 < 10) { // 10% chance of spawning an obstacle
                    Obstacle newObstacle(spawn_location, 0, 100, 100, 0, 2); // create a new obstacle
                    obstacles.push_back(newObstacle); // add to list
                }
            }
            if (spawn_location > 6)
            {
                //spawn left (30%)
                // Spawn obstacles at random intervals
                if (rand() % 100 < 10) { // 10% chance of spawning an obstacle
                    Obstacle newObstacle(spawn_location, 0, 100, 100, 0, 2); // create a new obstacle
                    obstacles.push_back(newObstacle); // add to list
                }                //spawn right (30%)
            }
            else
            {
                //spawn left (30%)
                // Spawn obstacles at random intervals
                if (rand() % 100 < 10) { // 10% chance of spawning an obstacle
                    Obstacle newObstacle(spawn_location, 0, 100, 100, 0, 2); // create a new obstacle
                    obstacles.push_back(newObstacle); // add to list
                }               // spawn mid (40%)
            }
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
