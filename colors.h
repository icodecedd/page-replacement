#include <stdio.h>

//7 Main 7 Colors 
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define MAGENTA     "\x1b[35m"
#define CYAN        "\x1b[36m"
#define WHITE       "\x1b[37m"

//Background Colors
#define BG_RED      "\x1b[41m"
#define BG_GREEN    "\x1b[42m"
#define BG_YELLOW   "\x1b[43m"
#define BG_BLUE     "\x1b[44m"
#define BG_MAGENTA  "\x1b[45m"
#define BG_CYAN     "\x1b[46m"
#define BG_WHITE    "\x1b[47m"

//Bright Colors
#define BRIGHT_BLACK "\033[100m"
#define BRIGHT_RED "\033[101m"
#define BRIGHT_GREEN "\033[102m"
#define BRIGHT_YELLOW "\033[103m"
#define BRIGHT_BLUE "\033[104m"
#define BRIGHT_MAGENTA "\033[105m"
#define BRIGHT_CYAN "\033[106m"
#define BRIGHT_WHITE "\033[107m"

//Other Function
#define BOLD        "\x1b[1m"
#define RESET       "\x1b[0m"
#define UNDERLINE   "\x1b[4m"
#define p printf
#define s scanf
