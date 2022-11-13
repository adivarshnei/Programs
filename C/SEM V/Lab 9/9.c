// 9. Write a program to implement Dijkstra's Algorithm

// Included Libraries
#include <stdio.h>    // IO and other operations
#include <stdlib.h>   // Memory operations and atoi()
#include <limits.h>   // INT_MAX
#include <stdbool.h>  // bool

// Macro Definitions
#define NODE_COUNT_STR argv[1]  // Command line argument for number of nodes
#define EDGE_COUNT_STR argv[2]  // Command line argument for number of edges

void matrix_print(int const** matrix, int const len);
int  extract_min(int const* array, int const len, bool const* set);
void print_paths(int const* prevs,
                 int const* distances,
                 int const  source,
                 int const  len);
void dijkstra(int const** adj, int const node_count, int const source);

int
main(int argc, char** argv) {
    if ( ! NODE_COUNT_STR || ! EDGE_COUNT_STR || argc != 3 ) {
        return 0;
    }

    int  node_count = atoi(NODE_COUNT_STR);
    int  source     = 0;
    int* adj[]      = {
             (int[]) {      0,      10, INT_MAX,       5, INT_MAX},
             (int[]) {INT_MAX,       0,       1,       2, INT_MAX},
             (int[]) {INT_MAX, INT_MAX,       0, INT_MAX,       4},
             (int[]) {INT_MAX,       3,       9,       0,       2},
             (int[]) {      7, INT_MAX,       6, INT_MAX,       0},
    };

    fprintf(stdout, "Adjacency Matrix:\n");
    matrix_print(( int const** ) adj, node_count);

    dijkstra(( int const** ) adj, node_count, source);

    return 0;
}

void
matrix_print(int const** matrix, int const len) {
    fprintf(stdout, "+");

    for ( int i = -2; i < len; i++ ) {
        if ( i == -1 ) {
            fprintf(stdout, "+");
        } else {
            fprintf(stdout, "----");
        }
    }

    fprintf(stdout, "+\n|    |");

    for ( int i = 0; i < len; i++ ) {
        fprintf(stdout, "%3d ", i);
    }

    fprintf(stdout, "|\n+");

    for ( int i = -2; i < len; i++ ) {
        if ( i == -1 ) {
            fprintf(stdout, "+");
        } else {
            fprintf(stdout, "----");
        }
    }

    fprintf(stdout, "+\n|");

    for ( int i = 0; i < len; i++ ) {
        for ( int j = -2; j < len; j++ ) {
            if ( j == -2 ) {
                fprintf(stdout, "%3d ", i);
                continue;
            } else if ( j == -1 ) {
                fprintf(stdout, "|");
                continue;
            }

            if ( matrix[i][j] == INT_MAX ) {
                fprintf(stdout, "    ");
            } else {
                fprintf(stdout, "%3d ", matrix[i][j]);
            }
        }

        fprintf(stdout, "|\n|");
    }

    fprintf(stdout, "\b+");

    for ( int i = -2; i < len; i++ ) {
        if ( i == -1 ) {
            fprintf(stdout, "+");
        } else {
            fprintf(stdout, "----");
        }
    }

    fprintf(stdout, "+\n");
}

int
extract_min(int const* array, int const len, bool const* set) {
    int min_index = -1;

    for ( int i = 0; i < len; i++ ) {
        if ( set[i] == false ) {
            min_index = i;
            break;
        }
    }

    for ( int i = 1; i < len; i++ ) {
        if ( array[min_index] > array[i] && set[i] == false ) {
            min_index = i;
        }
    }

    return min_index;
}

void
print_paths(int const* prevs,
            int const* distances,
            int const  source,
            int const  len) {
    for ( int i = 0; i < len; i++ ) {
        if ( i != source ) {
            fprintf(stdout, "Path from %d to %d (Cost: %d): ", source, i,
                    distances[i]);
            int temp = prevs[i];
            fprintf(stdout, "%d", i);

            while ( temp != -1 ) {
                fprintf(stdout, " <- %d", temp);
                temp = prevs[temp];
            }

            fprintf(stdout, "\n");
        }
    }
}

void
dijkstra(int const** adj, int const node_count, int const source) {
    int   set_size  = 0;
    bool* set       = ( bool* ) malloc(node_count * sizeof(bool));
    int*  distances = ( int* ) malloc(node_count * sizeof(int));
    int*  prev      = ( int* ) malloc(node_count * sizeof(int));

    for ( int i = 0; i < node_count; i++ ) {
        set[i]       = false;
        distances[i] = INT_MAX;
        prev[i]      = -1;
    }

    distances[source] = 0;

    fprintf(stdout, "\n");

    while ( set_size < node_count ) {
        int u  = extract_min(distances, node_count, set);
        set[u] = true;
        set_size++;

        for ( int j = 0; j < node_count; j++ ) {
            if ( adj[u][j] != INT_MAX && adj[u][j] != 0 && set[j] == false ) {
                if ( distances[j] > distances[u] + adj[u][j] ) {
                    distances[j] = distances[u] + adj[u][j];
                    prev[j]      = u;
                }
            }
        }
    }

    fprintf(stdout, "Source: %d\n", source);
    fprintf(stdout, "Distance Array: ");

    for ( int k = 0; k < node_count; k++ ) {
        if ( distances[k] == INT_MAX ) {
            fprintf(stdout, "%c\t", 'I');
        } else {
            fprintf(stdout, "%d\t", distances[k]);
        }
    }

    fprintf(stdout, "\nPrevious Array: ");

    for ( int k = 0; k < node_count; k++ ) {
        fprintf(stdout, "%d\t", prev[k]);
    }

    fprintf(stdout, "\n\n");
    print_paths(prev, distances, source, node_count);

    free(set);
    free(distances);
    free(prev);
}
