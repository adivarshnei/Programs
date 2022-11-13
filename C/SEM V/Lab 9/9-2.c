// 9-2. Write a program to implement Bellman-Ford Algorithm

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NODE_COUNT_STR argv[1]  // Command line argument for number of nodes
#define EDGE_COUNT_STR argv[2]  // Command line argument for number of edges

void matrix_print(int const** matrix, int const len);
bool has_incoming(int const** adj, int const node_count, int const vertex);
void print_paths(int const* prevs,
                 int const* distances,
                 int const  source,
                 int const  len);
void bellman_ford(int const** adj, int const node_count, int const source);

int
main(int argc, char** argv) {
    if ( ! NODE_COUNT_STR || ! EDGE_COUNT_STR || argc != 3 ) {
        return 0;
    }

    int  node_count = atoi(NODE_COUNT_STR);
    int  source     = 0;
    int* adj[]      = {
             (int[]) {      0,       6, INT_MAX,       7, INT_MAX},
             (int[]) {INT_MAX,       0,       5,       8,      -4},
             (int[]) {INT_MAX,      -2,       0, INT_MAX, INT_MAX},
             (int[]) {INT_MAX, INT_MAX,      -3,       0,       9},
             (int[]) {      2, INT_MAX,       7, INT_MAX,       0},
    };

    fprintf(stdout, "Adjacency Matrix:\n");
    matrix_print(( int const** ) adj, node_count);

    bellman_ford(( int const** ) adj, node_count, source);

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
bellman_ford(int const** adj, int const node_count, int const source) {
    int* distances = ( int* ) malloc(node_count * sizeof(int));
    int* prev      = ( int* ) malloc(node_count * sizeof(int));

    for ( int i = 0; i < node_count; i++ ) {
        distances[i] = INT_MAX;
        prev[i]      = -1;
    }

    distances[source] = 0;

    for ( int i = 1; i <= node_count - 1; i++ ) {
        for ( int j = 0; j < node_count; j++ ) {
            for ( int u = 0; u < node_count; u++ ) {
                if ( adj[j][u] != 0 && adj[j][u] != INT_MAX &&
                     distances[u] > distances[j] + adj[j][u] ) {
                    distances[u] = distances[j] + adj[j][u];
                    prev[u]      = j;
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

    fprintf(stdout, "\nParent Array: ");

    for ( int k = 0; k < node_count; k++ ) {
        fprintf(stdout, "%d\t", prev[k]);
    }

    fprintf(stdout, "\n\n");

    print_paths(prev, distances, source, node_count);

    free(distances);
    free(prev);
}
