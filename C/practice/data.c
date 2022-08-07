#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int
main(int argc, char** argv) {
    srand(time(NULL));

    FILE* file = fopen("test.sql", "w");

    for ( int i = 0; i < atoi(argv[1]); i++ ) {
        int  adm_no = (rand() + 1000) % 9000;
        char name[3];

        for ( int i = 0; i < 3; i++ ) {
            name[i] = ((rand() % 26) + 'A');
        }

        float marks = (rand() % 100) + ( float ) (rand() % 100) / ( float ) 100;

        int fee_status = ( int ) (rand()) % 5;

        fprintf(file, "\t(%04d, \"", adm_no);

        for ( int i = 0; i < 3; i++ ) {
            fprintf(file, "%c", name[i]);
        }

        fprintf(file, "\", %02.2f, ", marks);

        if ( fee_status ) {
            fprintf(file, "\"PAID\"), ");
        } else {
            fprintf(file, "\"NOT PAID\"), ");
        }

        fprintf(file, "\n");
    }

    fclose(file);
}
