#include <stdio.h>

int
main(void) {
    auto func = [] (){
        printf("123");        
        return 5;
    };

    func();

    return 0;
}
