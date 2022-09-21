// TO DO:
// REMOVAL OF ELEMENT FROM SET
// SET INTERSECTION
// SET DIFFERENCE

#include <stdio.h>
#include <stdlib.h>

struct Set {
    int* data;
    int  size;
};

int         linear_search(int*, int, int, int);
struct Set* set_init(int*, int);
void        set_append(struct Set*, int);
void        set_display(struct Set*);
struct Set* set_union(struct Set*, struct Set*);

int
linear_search(int* array, int len, int query, int loc) {
    if ( loc < 0 ) {
        return -1;
    } else if ( array[loc] == query ) {
        return loc;
    }

    return linear_search(array, len, query, loc - 1);
}

struct Set*
set_init(int* array, int len) {
    struct Set* set = ( struct Set* ) malloc(sizeof(set));
    set->data       = NULL;
    set->size       = 0;

    if ( array != NULL ) {
        set->data = ( int* ) malloc(sizeof(int));

        for ( int i = 0; i < len; i++ ) {
            set_append(set, array[i]);
        }
    }

    return set;
}

void
set_append(struct Set* set, int value) {
    if ( linear_search(set->data, set->size, value, set->size - 1) == -1 ) {
        set->size++;

        set->data = ( int* ) realloc(set->data, set->size * sizeof(int));
        set->data[set->size - 1] = value;
    }
}

void
set_display(struct Set* set) {
    fprintf(stdout, "%d: ", set->size);

    for ( int i = 0; i < set->size; i++ ) {
        fprintf(stdout, "%d, ", set->data[i]);
    }

    fprintf(stdout, "\n");
}

struct Set*
set_union(struct Set* set1, struct Set* set2) {
    struct Set* result = set_init(set1->data, set1->size);

    for ( int i = 0; i < set2->size; i++ ) {
        set_append(result, set2->data[i]);
    }

    return result;
}

int
main(int argc, char** argv) {
    int         array1[] = { 1, 2, 3, 1, 2, 3, 4 };
    int         array2[] = { 2, 3, 4, 5, 4, 5, 6 };
    struct Set* set1     = set_init(array1, sizeof(array1) / sizeof(array1[0]));
    struct Set* set2     = set_init(array2, sizeof(array2) / sizeof(array2[0]));
    set_display(set1);
    set_display(set2);

    struct Set* u = set_union(set1, set2);
    set_display(u);
    return 0;
}