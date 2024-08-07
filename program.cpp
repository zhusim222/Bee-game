// import
#include "splashkit.h"
#include "globals.h" // <- added this import
#include <graphics.h>
#include <cstdlib>



int main()
{
    open_window("BeeFall", 1280, 960); //named window beefall and window size
    hide_mouse(); // hide mouse while cursor is over game window
    while (!quit_requested())
    {
        process_events();
        clear_screen();
        
        if (key_down(RIGHT_KEY))
        {
            if (player_posx <= 880)
            {
                player_posx += 10.0f;
            }
        }
        if (key_down(LEFT_KEY))
        {
            if (player_posx >= 140)
            {
                player_posx -= 10.0f;
                
                
            }
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
        int spawn_number = (rand() % 1); // either 1 or 2 falling objects
        for (int i = 0; i <= spawn_number; i++)
        {
            int spawn_location = (rand() % 10);
            if (spawn_location < 3)
            {
                //spawn left (30%)
            }
            if (spawn_location > 6)
            {
                //spawn right (30%)
            }
            else
            {
                // spawn mid (40%)
            }
        }
                

        //redrawing the bitmap after every clear background and bee
        draw_bitmap(background, 0 , 0 , option_to_screen());
        draw_bitmap(Player, player_posx , player_posy , option_to_screen());
        refresh_screen(60);
    }
}
