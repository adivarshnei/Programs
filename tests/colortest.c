#include <stdio.h>

#define COLOR_BLACK_CODE  "\033[0;30m"
#define COLOR_RED_CODE    "\033[0;31m"
#define COLOR_GREEN_CODE  "\033[0;32m"
#define COLOR_YELLOW_CODE "\033[0;33m"
#define COLOR_BLUE_CODE   "\033[0;34m"
#define COLOR_PURPLE_CODE "\033[0;35m"
#define COLOR_CYAN_CODE   "\033[0;36m"
#define COLOR_WHITE_CODE  "\033[0:37m"
#define COLOR_RESET_CODE  "\033[0m"
#define COLORED(COLOR, CODE) \
    printf(COLOR);           \
    CODE;                    \
    printf(COLOR_RESET_CODE);

int
main(void) {
    COLORED(COLOR_RED_CODE, {
        printf("Hello World");
        printf("\nTheQuickBrownFox");

        COLORED(COLOR_BLUE_CODE, {
            printf("\nLol this is now blue");

            COLORED(COLOR_PURPLE_CODE, {
                printf("\nPretty Purple innit?");

                COLORED(COLOR_GREEN_CODE, {
                    printf("\nThis is");
                    printf("\nObjectively");
                    printf("\nThe Best Color");
                });
            });
        });
    });
}