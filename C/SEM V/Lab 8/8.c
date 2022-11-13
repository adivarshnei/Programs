// 8. Write a program to solve Travelling Salesperson Problem using Branch and
// Bound Approach

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MATRIX_SIZE   5
#define PRINT_SPACING 3

struct Node {
    int           index;
    int           cost;
    int**         adj;
    int           adj_len;
    struct Node** children;
    struct Node*  parent;
    int           children_count;
    int           max_children;
};

void         matrix_print(struct Node* node, bool print_children);
struct Node* node_init(int**     adj,
                       int const len,
                       int const index,
                       int const children);
void         node_dealloc(struct Node* node);
void         node_add_children(struct Node* node);
void         node_infinitize(struct Node* node, int const row, int const col);
void         node_row_col_reduce(struct Node* node);
void         tsp_branch_and_bound(struct Node* root);

int
main(int argc, char** argv) {
    int* adj[] = {
        (int[]) {INT_MAX,      20,      30,      10,      11},
         (int[]) {     15, INT_MAX,      16,       4,       2},
        (int[]) {      3,       5, INT_MAX,       2,       4},
         (int[]) {     19,       6,      18, INT_MAX,       3},
        (int[]) {     16,       4,       7,      16, INT_MAX}
    };

    struct Node* root = node_init(adj, MATRIX_SIZE, 1, MATRIX_SIZE - 1);

    tsp_branch_and_bound(root);

    node_dealloc(root);

    return 0;
}

void
matrix_print(struct Node* node, bool print_children) {
    fprintf(stdout, "+");

    for ( int i = -2; i < node->adj_len; i++ ) {
        if ( i == -1 ) {
            fprintf(stdout, "+");
        } else {
            fprintf(stdout, "----");
        }
    }

    fprintf(stdout, "+\n|    |");

    for ( int i = 0; i < node->adj_len; i++ ) {
        fprintf(stdout, "%3d ", i + 1);
    }

    fprintf(stdout, "|\n+");

    for ( int i = -2; i < node->adj_len; i++ ) {
        if ( i == -1 ) {
            fprintf(stdout, "+");
        } else {
            fprintf(stdout, "----");
        }
    }

    fprintf(stdout, "+\n|");

    for ( int i = 0; i < node->adj_len; i++ ) {
        for ( int j = -2; j < node->adj_len; j++ ) {
            if ( j == -2 ) {
                fprintf(stdout, "%3d ", i + 1);
                continue;
            } else if ( j == -1 ) {
                fprintf(stdout, "|");
                continue;
            }

            if ( node->adj[i][j] == INT_MAX ) {
                fprintf(stdout, "%3c ", 'I');
            } else {
                fprintf(stdout, "%3d ", node->adj[i][j]);
            }
        }

        fprintf(stdout, "|\n|");
    }

    fprintf(stdout, "\b+");

    for ( int i = -2; i < node->adj_len; i++ ) {
        if ( i == -1 ) {
            fprintf(stdout, "+");
        } else {
            fprintf(stdout, "----");
        }
    }

    fprintf(stdout, "+\n");

    fprintf(stdout, "Cost: %3d\n", node->cost);

    if ( print_children == true ) {
        for ( int i = 0; i < node->children_count; i++ ) {
            fprintf(stdout, "\n(%d, %d)\n", node->index,
                    node->children[i]->index);

            matrix_print(node->children[i], true);
        }
    }
}

struct Node*
node_init(int** adj, int const len, int const index, int const children) {
    struct Node* node = ( struct Node* ) malloc(sizeof(struct Node));

    node->index          = index;
    node->adj_len        = len;
    node->cost           = 0;
    node->children       = NULL;
    node->parent         = NULL;
    node->children_count = 0;
    node->max_children   = children;
    node->adj            = ( int** ) malloc(node->adj_len * sizeof(int*));

    for ( int i = 0; i < node->adj_len; i++ ) {
        node->adj[i] = ( int* ) malloc(node->adj_len * sizeof(int));
        memcpy(node->adj[i], adj[i], node->adj_len * sizeof(int));
    }

    return node;
}

void
node_dealloc(struct Node* node) {
    if ( node == NULL ) {
        return;
    }

    for ( int i = 0; i < node->children_count; i++ ) {
        node_dealloc(node->children[i]);
    }

    for ( int i = 0; i < node->adj_len; i++ ) {
        free(node->adj[i]);
    }

    if ( node->children != NULL ) {
        free(node->children);
        node->children = NULL;
    }

    free(node->adj);
    free(node);
}

void
node_add_children(struct Node* node) {
    node->children =
        ( struct Node** ) malloc(node->max_children * sizeof(struct Node*));

    int          index_occurance[MATRIX_SIZE] = { 0 };
    struct Node* temp                         = node;

    while ( temp != NULL ) {
        index_occurance[temp->index - 1] = 1;
        temp                             = temp->parent;
    }

    for ( int i = 0; i < node->max_children; i++ ) {
        int index = 1;

        while ( index_occurance[index - 1] == 1 ) {
            index++;
        }

        index_occurance[index - 1] = 1;

        node->children[i] =
            node_init(node->adj, node->adj_len, index, node->max_children - 1);
        node->children[i]->parent = node;
        node->children_count++;

        index++;

        node_infinitize(node->children[i], node->index - 1,
                        node->children[i]->index - 1);
    }
}

void
node_infinitize(struct Node* node, int const row, int const col) {
    for ( int i = 0; i < node->adj_len; i++ ) {
        node->adj[row][i] = INT_MAX;
        node->adj[i][col] = INT_MAX;
    }

    node->adj[col][0] = INT_MAX;
}

void
node_row_col_reduce(struct Node* node) {
    int row_reductions = 0;
    int col_reductions = 0;

    for ( int i = 0; i < node->adj_len; i++ ) {
        int min_row = INT_MAX;

        for ( int j = 0; j < node->adj_len; j++ ) {
            min_row = (node->adj[i][j] < min_row) ? node->adj[i][j] : min_row;
        }

        if ( min_row != 0 ) {
            for ( int j = 0; j < node->adj_len; j++ ) {
                if ( node->adj[i][j] == INT_MAX ) {
                    continue;
                }

                node->adj[i][j] -= min_row;
            }
        }

        if ( min_row != INT_MAX ) {
            row_reductions += min_row;
        }
    }

    for ( int i = 0; i < node->adj_len; i++ ) {
        int min_col = INT_MAX;

        for ( int j = 0; j < node->adj_len; j++ ) {
            min_col = (node->adj[j][i] < min_col) ? node->adj[j][i] : min_col;
        }

        if ( min_col != 0 ) {
            for ( int j = 0; j < node->adj_len; j++ ) {
                if ( node->adj[j][i] == INT_MAX ) {
                    continue;
                }

                node->adj[j][i] -= min_col;
            }
        }

        if ( min_col != INT_MAX ) {
            col_reductions += min_col;
        }
    }

    node->cost = row_reductions + col_reductions;
}

void
tsp_branch_and_bound(struct Node* root) {
    node_row_col_reduce(root);

    struct Node* temp = root;

    matrix_print(root, true);

    while ( temp->max_children != 0 ) {
        node_add_children(temp);

        for ( int i = 0; i < temp->max_children; i++ ) {
            node_row_col_reduce(temp->children[i]);
        }

        for ( int i = 0; i < temp->max_children; i++ ) {
            temp->children[i]->cost += temp->cost;
            temp->children[i]->cost +=
                root->adj[temp->index - 1][temp->children[i]->index - 1];
        }

        int min_index = 0;

        for ( int i = 0; i < temp->max_children; i++ ) {
            if ( temp->children[i]->cost < temp->children[min_index]->cost ) {
                min_index = i;
            }
        }

        temp = temp->children[min_index];
    }

    matrix_print(root, true);

    temp = root;

    fprintf(stdout, "Closed TSP Path: %d", temp->index);

    while ( temp->max_children != 0 ) {
        int min_index = 0;

        for ( int i = 0; i < temp->max_children; i++ ) {
            if ( temp->children[i]->cost < temp->children[min_index]->cost ) {
                min_index = i;
            }
        }

        temp = temp->children[min_index];

        fprintf(stdout, " -> %d", temp->index);
    }

    fprintf(stdout, " -> %d", root->index);
}
