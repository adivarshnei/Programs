#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
   printf("%d", valid_signal(100));
}
