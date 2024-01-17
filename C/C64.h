// C64 Specific Code
#include<peekpoke.h>

// Color Macros
#define C64_COLOR_BLACK  0x00U
#define C64_COLOR_WHITE  0x01U
#define C64_COLOR_RED    0x02U
#define C64_COLOR_CYAN   0x03U
#define C64_COLOR_PURPLE 0x04U
#define C64_COLOR_GREEN  0x05U
#define C64_COLOR_BLUE   0x06U
#define C64_COLOR_YELLOW 0x07U
#define C64_COLOR_ORANGE 0x08U
#define C64_COLOR_BROWN  0x09U
#define C64_COLOR_PINK   0x0AU
#define C64_COLOR_DGREY  0x0BU
#define C64_COLOR_GREY   0x0CU
#define C64_COLOR_LGREEN 0x0DU
#define C64_COLOR_LBLUE  0x0EU
#define C64_COLOR_LGREY  0x0FU

// Screen Macros
#define BASE_SCREEN_ADDRESS 33792U
#define BASE_HIRES_ADDRESS  40960U

#define CLRSCR \
__asm__("lda #$93"); \
__asm__("jsr $ffd2");

#define SET_COLORS(border,back,text) \
    POKE(0xD020,border); \
    POKE(0xD021,back); \
    POKE(0x286,text);

#define SET_HIRES \
    POKE(53272U,(PEEK(53272U) | 8)); \
    POKE(56576U,(PEEK(56576U) & 252) | 1); \
    POKE(53265U,(PEEK(53265U) | 32));