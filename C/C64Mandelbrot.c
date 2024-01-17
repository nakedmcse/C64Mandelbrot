// C64 Mandelbrot C version
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "C64.h"
#include "float.h"
#include "math.h"

void setupScreen() {
    CLRSCR;
    SET_COLORS(C64_COLOR_BLACK,C64_COLOR_BLACK,C64_COLOR_BLUE);
    memset((void *)BASE_HIRES_ADDRESS,0,7999U);  // 0 out screen memory
    memset((void *)BASE_SCREEN_ADDRESS,(C64_COLOR_BLUE << 4)|C64_COLOR_BLACK,1024);  // Set black/blue colors
    SET_HIRES;
}

void plot(int x, int y) {
    int ch = x/8;
    int ro = y/8;
    int ln = y & 7;
    unsigned int by=BASE_HIRES_ADDRESS+(ro*320)+(8*ch)+ln;
    int bi = 7-(x & 7);
    POKE(by,(PEEK(by) | (1<<bi)));
}

int main(void) {
    int x;
    int y;

    setupScreen();

    // Mandelbrot Reduced Iter
    for(y=0; y<200; y++) {
        for(x=0; x<320; x++) {
            float xo = ((itof(x)*2.47)/320)-2.0;
            float yo = ((itof(y)*2.24)/200)-1.12;
            int i = 0;
            float tx = 0;
            float ty = 0;
            float xtemp = 0;

            while(i<11 && ((tx*tx)+(ty*ty))<=400) {
                xtemp = (tx*tx)-(ty*ty)+xo;
                ty = (2*(tx*ty))+yo;
                tx = xtemp;
                i++;
            }

            if(i<11) {
                plot(x,y);
            }
        }
    }

    // Hold screen
    for(;;);
    
    return 0;
}