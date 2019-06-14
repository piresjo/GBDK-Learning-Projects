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
        if (currSpriteIndex == 0) {
            currSpriteIndex = 1;
        } else {
            currSpriteIndex = 0;
        }
        set_sprite_tile(0, currSpriteIndex);
        delay(1000); //delay the loop for 1000 Z80 cycles
        scroll_sprite(0, 10, 0); //mode_sprite helps jump  sprites, scroll is bettwe for animation
    }
}