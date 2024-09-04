#include "splashkit.h"
#include "globals.h"
#include "player.h"
#include "bullet_factory.h"
#include <vector>
#include <cmath>
#include <iostream>
//skm g++ program.cpp player.cpp bullet_factory.cpp globals.cpp -o game.exe

int main() {
    open_window("BeeFall", 1280, 960);
    hide_mouse();
    
    Player player(480.0f, 550.0f, 10.0f);
    std::vector<sprite> bullets;
    
    // Check if bullet bitmap is loaded correctly
    if (!bitmap_valid(bullet)) {
        std::cout << "Error: Could not load bullet bitmap" << std::endl;
        return 1;
    }
    
    while (!quit_requested()) {
        process_events();
        clear_screen(COLOR_BLACK);
        
        if (key_down(RIGHT_KEY)) {
            player.move_right();
        }
        if (key_down(LEFT_KEY)) {
            player.move_left();
        }
        
        // Shoot bullets when spacebar is pressed
        if (key_typed(SPACE_KEY)) {
            point_2d origin = point_at(player.get_x() + 32, player.get_y()); // Adjust based on player sprite size
            vector_2d direction = vector_to(0, -1); // Shoot upwards
            int bulletCount = 5;
            float spreadAngle = 45 * (std::atan(1) * 4 / 180); // 45 degrees in radians
            
            std::vector<sprite> newBullets = BulletFactory::SprayProjectiles(ProjectileType::NORMAL, origin, direction, bulletCount, spreadAngle);
            bullets.insert(bullets.end(), newBullets.begin(), newBullets.end());
            
            std::cout << "Created " << newBullets.size() << " bullets" << std::endl;
        }
        
        // Draw background
        draw_bitmap(background, 0, 0, option_to_screen());
        
        // Update and draw bullets
        for (auto it = bullets.begin(); it != bullets.end();) {
            update_sprite(*it);
            
            // Remove bullets that are off-screen
            if (sprite_y(*it) < -50 || sprite_y(*it) > 1010 || sprite_x(*it) < -50 || sprite_x(*it) > 1330) {
                free_sprite(*it);
                it = bullets.erase(it);
            } else {
                draw_sprite(*it);
                
                // Debug: Draw a red circle around each bullet
                point_2d bullet_pos = sprite_position(*it);
                fill_circle(COLOR_RED, bullet_pos.x, bullet_pos.y, 5);
                
                ++it;
            }
        }
        
        // Draw player
        draw_bitmap(bee, player.get_x(), player.get_y(), option_to_screen());
        
        // Debug: Display bullet count
        draw_text("Bullets: " + std::to_string(bullets.size()), COLOR_WHITE, 10, 10);
        
        refresh_screen(60);
    }
    
    // Clean up remaining bullets
    for (auto& bullet : bullets) {
        free_sprite(bullet);
    }
    
    return 0;
}