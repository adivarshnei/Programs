// Open Ended 2: Write a program to implement Floyd-Warshall's Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_TO_CHAR(A) (A + 48)

enum Status {
    VALUE    = 0,
    INFINITY = 1
};

struct Weight {
    enum Status status;
    int         weight;
};

void          print_weight_matrix(struct Weight** matrix, int len);
void          print_parent_matrix(char** matrix, int len);
struct Weight add_element(struct Weight e1, struct Weight e2);
struct Weight min_element(struct Weight e1, struct Weight e2);
void          floyd_warshall(struct Weight** adj, int len);

int
main(int argc, char** argv) {
    int            node_count = 5;
    struct Weight* adj[]      = {
             (struct Weight[]) {   { .status = VALUE, .weight = 0 },
                                { .status = VALUE, .weight = 3 },
                                { .status = VALUE, .weight = 8 },
                                { .status = INFINITY, .weight = 0 },
                                { .status = VALUE, .weight = -4 }  },
             (struct Weight[]) {{ .status = INFINITY, .weight = 0 },
                                { .status = VALUE, .weight = 0 },
                                { .status = INFINITY, .weight = 0 },
                                { .status = VALUE, .weight = 1 },
                                { .status = VALUE, .weight = 7 }   },
             (struct Weight[]) {{ .status = INFINITY, .weight = 0 },
                                { .status = VALUE, .weight = 4 },
                                { .status = VALUE, .weight = 0 },
                                { .status = INFINITY, .weight = 0 },
                                { .status = INFINITY, .weight = 0 }},
             (struct Weight[]) {   { .status = VALUE, .weight = 2 },
                                { .status = INFINITY, .weight = 0 },
                                { .status = VALUE, .weight = -5 },
                                { .status = VALUE, .weight = 0 },
                                { .status = INFINITY, .weight = 0 }},
             (struct Weight[]) {{ .status = INFINITY, .weight = 0 },
                                { .status = INFINITY, .weight = 0 },
                                { .status = INFINITY, .weight = 0 },
                                { .status = VALUE, .weight = 6 },
                                { .status = VALUE, .weight = 0 }   }
    };

    fprintf(stdout, "%d\n", node_count);
    print_weight_matrix(adj, node_count);
    floyd_warshall(adj, node_count);

    return 0;
}

void
print_weight_matrix(struct Weight** matrix, int len) {
    for ( int i = 0; i < len; i++ ) {
        for ( int j = 0; j < len; j++ ) {
            if ( matrix[i][j].status == INFINITY ) {
                fprintf(stdout, "  %c", 'I');
            } else {
                fprintf(stdout, "%3d", matrix[i][j].weight);
            }
        }

        fprintf(stdout, "\n");
    }
}

void
print_parent_matrix(char** matrix, int len) {
    for ( int i = 0; i < len; i++ ) {
        for ( int j = 0; j < len; j++ ) {
            fprintf(stdout, "%3c", matrix[i][j]);
        }

        fprintf(stdout, "\n");
    }
}

struct Weight
add_element(struct Weight w1, struct Weight w2) {
    if ( w1.status == INFINITY ) {
        return w1;
    } else if ( w2.status == INFINITY ) {
        return w2;
    } else {
        return (struct Weight) { .status = VALUE,
                                 .weight = w1.weight + w2.weight };
    }
}

struct Weight
min_element(struct Weight w1, struct Weight w2) {
    if ( w2.status == INFINITY ) {
        return w1;
    } else if ( w1.status == INFINITY ) {
        return w2;
    } else {
        return (w1.weight <= w2.weight) ? w1 : w2;
    }
}

void
floyd_warshall(struct Weight** adj, int len) {
    struct Weight** D =
        ( struct Weight** ) malloc(len * sizeof(struct Weight*));
    struct Weight** D_new =
        ( struct Weight** ) malloc(len * sizeof(struct Weight*));
    char** parent     = ( char** ) malloc(len * sizeof(char*));
    char** parent_new = ( char** ) malloc(len * sizeof(char*));

    for ( int i = 0; i < len; i++ ) {
        D[i]          = ( struct Weight* ) malloc(len * sizeof(struct Weight));
        D_new[i]      = ( struct Weight* ) malloc(len * sizeof(struct Weight));
        parent[i]     = ( char* ) malloc(len * sizeof(char));
        parent_new[i] = ( char* ) malloc(len * sizeof(char));

        for ( int j = 0; j < len; j++ ) {
            D_new[i][j].status = VALUE;
            D_new[i][j].weight = 0;
        }
    }

    for ( int i = 0; i < len; i++ ) {
        memcpy(D[i], adj[i], len * sizeof(struct Weight));
    }

    for ( int i = 0; i < len; i++ ) {
        for ( int j = 0; j < len; j++ ) {
            if ( i == j ) {
                parent[i][j] = 'N';
            } else if ( D[i][j].status == INFINITY ) {
                parent[i][j] = 'N';
            } else {
                parent[i][j] = INT_TO_CHAR(i + 1);
            }
        }
    }

    for ( int k = 0; k < len; k++ ) {
        for ( int i = 0; i < len; i++ ) {
            for ( int j = 0; j < len; j++ ) {
                struct Weight temp = add_element(D[i][k], D[k][j]);

                D_new[i][j] = min_element(D[i][j], temp);

                if ( D[i][j].status == INFINITY ) {
                    parent_new[i][j] = parent[k][j];
                } else if ( temp.status == INFINITY ) {
                    parent_new[i][j] = parent[i][j];
                } else {
                    if ( D[i][j].weight > temp.weight ) {
                        parent_new[i][j] = parent[k][j];
                    } else {
                        parent_new[i][j] = parent[i][j];
                    }
                }
            }
        }

        for ( int i = 0; i < len; i++ ) {
            memcpy(D[i], D_new[i], len * sizeof(struct Weight));
            memcpy(parent[i], parent_new[i], len * sizeof(char));
        }
    }

    print_weight_matrix(D, len);
    print_parent_matrix(parent, len);

    for ( int i = 0; i < len; i++ ) {
        free(D[i]);
        free(D_new[i]);
        free(parent[i]);
        free(parent_new[i]);
    }

    free(D);
    free(D_new);
    free(parent);
    free(parent_new);
}
