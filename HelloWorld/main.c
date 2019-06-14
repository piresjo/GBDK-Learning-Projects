/* For the include statements, while VSCode panics upon seeing these
 * the GBDK will read it just fine (assuming no other errors)
 * at the very least, these two libraries should be included
 */

#include <gb/gb.h>
#include <stdio.h>

// Thanks to the compiler, all we need to do is use standard output
// With standard output, it displays in both upper and lower case

void main() {
    printf("Hello World\n");
}