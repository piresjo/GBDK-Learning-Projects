#include <gb/gb.h>
#include "background.c"
#include "backgroundSprites.c"

void main() {
    set_bkg_data(0, 7, backgroundTiles); // loads the tiles for the background into memory
    set_bkg_tiles(0, 0, 40, 18, background); // loads the background map as a whole on the screen

    SHOW_BKG; // show background
    DISPLAY_ON; // turn on display for background

    // for scrolling background
    while(1) {
        scroll_bkg(1, 0); // move background (in this case, scrolls right by 1)
        delay(100);
    }
}