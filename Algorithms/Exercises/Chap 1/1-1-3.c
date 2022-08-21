#include <stdio.h>
#include <stdlib.h>

typedef unsigned int LoopVar;
typedef char         BufferClear;

enum Bool {
    TRUE  = 1,
    FALSE = 0
};

void equalChk(int, int, int);

BufferClear temp;
enum Bool   shouldRepeat;

int
main(void) {
    int num1;
    int num2;
    int num3;

    system("cls");

    printf("Enter the numbers: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    equalChk(num1, num2, num3);

    printf("\nRepeat Program? (1 = YES): ");
    scanf("%d", &shouldRepeat);
    scanf("%c", &temp);

    (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void
equalChk(int num1, int num2, int num3) {
    (num1 == num2) ? ((num2 == num3) ? printf("equal") : printf("not equal"))
                   : printf("not equal");
}
