#include <gb/gb.h>
#include "background.c"
#include "backgroundSprites.c"
#include <gb/font.h> //gbdk has a font library, so include it
#include "windowmap.c" // The file showcases "HELLO" in the HUD

void main() {
    font_t min_font;

    font_init();
    min_font = font_load(font_min);
    font_set(min_font);

    // These above four lines are needed to set and load the font

    // However, the font tiles share the same memory as the graphics, so the tiles 
    // need to be loaded differently, and the tile map needs to be modified

    set_bkg_data(37, 7, backgroundTiles); // loads the tiles for the background into memory
    set_bkg_tiles(0, 0, 40, 18, background); // loads the background map as a whole on the screen

    // set up heads up display
    set_win_tiles(0, 0, 5, 1, windowMap); //generate the HUD, needs a map file, so create one
    move_win(7, 120); // limitation - it's not easy to do a HUD up top, will need to work on that later

    SHOW_BKG; // show background
    SHOW_WIN; // show the HUD, but the window isn't transparent
    DISPLAY_ON; // turn on display for background

    while(1) {
        scroll_bkg(1, 0); // move background (in this case, scrolls right by 1)
        delay(100);
    }

}