#include <stdio.h>
#include <windows.h>
#include <wchar.h>

#define CLEAR()             printf("\033[H\033[J")
#define COLOR_BLACK_CODE    "\033[0;30m"
#define COLOR_RED_CODE      "\033[0;31m"
#define COLOR_GREEN_CODE    "\033[0;32m"
#define COLOR_YELLOW_CODE   "\033[0;33m"
#define COLOR_BLUE_CODE     "\033[0;34m"
#define COLOR_PURPLE_CODE   "\033[0;35m"
#define COLOR_CYAN_CODE     "\033[0;36m"
#define COLOR_WHITE_CODE    "\033[0:37m"
#define COLOR_RESET_CODE    "\033[0m"
#define COLORED_TEXT(COLOR) printf(COLOR)
#define COLOR_RESET()       printf(COLOR_RESET_CODE)
#define GOTOXY(X, Y)        printf("\033[%d;%dH", Y, X)

int
main(int argc, char** argv) {
    int   i        = 1;
    int   j        = 1;
    int   i_off    = 1;
    int   j_off    = 1;
    char  print    = '0';
    int   color    = 0;
    char* colors[] = {
        COLOR_BLACK_CODE,  COLOR_RED_CODE,   COLOR_GREEN_CODE,
        COLOR_YELLOW_CODE, COLOR_BLUE_CODE,  COLOR_PURPLE_CODE,
        COLOR_CYAN_CODE,   COLOR_WHITE_CODE,
    };

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int                        columns;
    int                        rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows    = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    while ( 1 ) {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows    = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        // char string[] = argv[1];
        int len = strlen(argv[1]);
        // int len = 6;

        // CLEAR();
        COLORED_TEXT(colors[color]);
        GOTOXY(i, j);
        // GOTOXY(i - 1, j - 1);
        // printf("%c, %d\n%2d, %2d", print, print, i, j);
        // printf("###");
        // GOTOXY(i, j - 1);
        // printf("%c", print);
        // printf(" ");
        printf("%s", argv[1]);
        // for ( int i = 0; i < len; i++ ) {
        // printf("%lc", ( wint_t ) 9619);
        // }
        // printf(" ");
        // GOTOXY(i + 1, j - 1);
        // printf("###");
        COLOR_RESET();
        Sleep(atoi(argv[2]));

        i += i_off;
        j += j_off;
        print += 1;
        color += 1;

        if ( i >= columns - (len - 1) || i <= 0 ) {
            i_off *= -1;
        }
        if ( j >= rows || j <= 0 ) {
            j_off *= -1;
        }

        if ( print > '9' ) {
            print = '1';
        }

        if ( color > 7 ) {
            color = 0;
        }

        if ( i >= columns - (len - 1) ) {
            i = columns - (len - 1);
        }
        if ( j >= rows ) {
            j = rows;
        }
    }
}
