#include <stdio.h>
#include <windows.h>

#define CLEAR()      printf("\033[H\033[J")
#define GOTOXY(X, Y) printf("\033[%d;%dH", (Y), (X))

int
main(void) {
    int number;

    for ( int i = 0; i < 10; i++ ) {
        CLEAR();
        GOTOXY(i, i);
        printf("1");
        Sleep(10);
    }
}