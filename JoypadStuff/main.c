#include <gb/gb.h>
#include <stdio.h>
#include "Sprites.c"

void main () {
    UINT8 currSpriteIndex = 0;

    set_sprite_data(0, 2, Sprites); // loads both sprites made into data
    set_sprite_tile(0, 0); // utlize the first of the two sprites
    move_sprite(0, 88, 78); // place the first sprite in the middle of the screen
    SHOW_SPRITES; // Flag used to show sprites

    // Continuous loop for animation
    while (1) {
        // joypad() determines what button on the joypad is being pressed
        // J_LEFT is for when the joypad is pressed left, and so on
        // Still a naive implementation; still doesn't check if at end of screen
        switch (joypad()) {
            case J_LEFT:
                scroll_sprite(0, -10, 0); 
                break;
            case J_RIGHT:
                scroll_sprite(0, 10, 0);
                break;
            case J_UP:
                scroll_sprite(0, 0, -10);
                break;
            case J_DOWN:
                scroll_sprite(0, 0, 10);
                break;
        }
        delay(100); //delay the loop for 1000 Z80 cycles
        
    }
}