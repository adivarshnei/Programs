// Exercise 1-22
// Write a program to "fold" long input lines into two or more shorter lines
// after the last non-blank character that occurs before the n-th column of
// input

#include <stdio.h>

#define MAX_LENGTH   1000
#define LINE_LENGTH  40
#define TAB_LENGTH   8
#define NO_BLANK     -1
#define TAB_LOC(ARG) (TAB_LENGTH - (ARG % TAB_LENGTH))
#define LINE_POS_CHK()                   \
    if ( line_pos + 1 >= LINE_LENGTH ) { \
        printf("- %d\n", line_pos);      \
                                         \
        line_pos = 0;                    \
        i++;                             \
                                         \
        continue;                        \
    }

int  get_line(char[], int);
int  next_blank(char[], int, int);
int  last_blank(char[], int, int);
void print_folded(char[]);

int
main(int argc, char** argv) {
    char line[MAX_LENGTH];
    int  length;

    length = get_line(line, MAX_LENGTH);

    printf("%d\n", last_blank(line, 0, LINE_LENGTH));

    print_folded(line);

    return 0;
}

int
get_line(char line[], int lim) {
    int c;
    int i = 0;

    while ( (c = getchar()) != EOF ) {
        if ( i >= lim - 1 || c == '\n' ) {
            break;
        }

        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

int
next_blank(char line[], int start, int end) {
    int i = start;

    while ( line[i] != '\0' && i < end ) {
        if ( line[i] == ' ' || line[i] == '\t' || line[i] == '\n' ) {
            return i;
        }

        i++;
    }

    return NO_BLANK;
}

int
last_blank(char line[], int start, int end) {
    int i         = start;
    int blank_pos = NO_BLANK;

    while ( line[i] != '\0' && i < end ) {
        if ( line[i] == ' ' || line[i] == '\t' || line[i] == '\n' ) {
            blank_pos = i;
        }

        i++;
    }

    return blank_pos;
}

void
print_folded(char line[]) {
    int i        = 0;
    int temp     = 0;
    int line_pos = 0;

    while ( line[i] != '\0' ) {
        if ( line_pos + 1 >= LINE_LENGTH ) {
            printf("- %d\n", line_pos);

            line_pos = 0;
            i++;

            continue;
        }

        if ( (temp = last_blank(line, i, LINE_LENGTH + i)) != NO_BLANK ) {
            while ( i < temp ) {
                printf("%c", line[i++]);
                line_pos++;

                if ( line_pos + 1 >= LINE_LENGTH ) {
                    printf("- %d\n", line_pos);

                    line_pos = 0;
                    i++;

                    goto BREAK_POINT;
                }
            }

            printf(" %d\n", line_pos);

            line_pos = 0;
            i++;

            continue;
        }

    BREAK_POINT:

        printf("%c", line[i]);

        line_pos++;
        i++;
    }

    printf("(end)\n");
}
