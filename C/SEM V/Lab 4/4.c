// Write a program to implement Kruskal's Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE_COUNT_STR argv[1]
#define EDGE_COUNT_STR argv[2]
#define ENTER_FUNC()   fprintf(stdout, "Entering Func: %s\n", __func__);
#define EXIT_FUNC()    fprintf(stdout, "Exiting Func: %s\n", __func__);

// node_count = 9
// edge_count = 12

#define EDGESWAP(A, B)    \
    struct Edge temp = A; \
    A                = B; \
    B                = temp;

struct Edge {
    int start;
    int end;
    int weight;
};

struct Graph {
    int          node_count;
    int          edge_count;
    struct Edge* edges;
    int**        adj;
};

void          print_matrix(int**, int);
struct Graph* graph_init(int);
void          populate_graph(struct Graph*, struct Edge*, int);
void          edge_sort(struct Graph*);
void          mst_kruskal(struct Graph*);

int
main(int argc, char** argv) {
    ENTER_FUNC();
    if ( NODE_COUNT_STR == NULL ) {
        return 0;
    }

    struct Graph* graph = graph_init(atoi(NODE_COUNT_STR));

    struct Edge edges[] = {
        {.start = 0, .end = 1,  .weight = 4},
        {.start = 0, .end = 7,  .weight = 8},
        {.start = 1, .end = 2,  .weight = 8},
        {.start = 1, .end = 7, .weight = 11},
        {.start = 2, .end = 3,  .weight = 7},
        {.start = 3, .end = 4,  .weight = 9},
        {.start = 3, .end = 5, .weight = 14},
        {.start = 4, .end = 5, .weight = 10},
        {.start = 5, .end = 6,  .weight = 2},
        {.start = 6, .end = 7,  .weight = 1},
        {.start = 6, .end = 8,  .weight = 6},
        {.start = 7, .end = 8,  .weight = 7}
    };

    populate_graph(graph, edges, atoi(EDGE_COUNT_STR));

    // print_matrix(graph->adj, graph->node_count);
    edge_sort(graph);

    // for ( int i = 0; i < graph->edge_count; i++ ) {
    // fprintf(stdout, "%d ", graph->edges[i].weight);
    // }

    mst_kruskal(graph);

    {
        free(graph->edges);

        for ( int i = 0; i < graph->edge_count; i++ ) {
            free(graph->adj[i]);
        }

        free(graph->adj);
        free(graph);
    }

    EXIT_FUNC();
    return 0;
}

void
print_matrix(int** matrix, int len) {
    ENTER_FUNC();
    for ( int i = 0; i < len; i++ ) {
        for ( int j = 0; j < len; j++ ) {
            if ( matrix[i][j] == 0 ) {
                printf("%2d ", matrix[i][j]);
            } else {
                printf("%2d ", matrix[i][j]);
            }
        }

        printf("\n");
    }
    EXIT_FUNC();
}

struct Graph*
graph_init(int node_count) {
    ENTER_FUNC();
    struct Graph* graph = ( struct Graph* ) malloc(sizeof(struct Graph));
    graph->node_count   = node_count;
    graph->adj          = ( int** ) malloc(graph->node_count * sizeof(int*));
    graph->edge_count   = 0;
    graph->edges        = NULL;

    for ( int i = 0; i < graph->node_count; i++ ) {
        graph->adj[i] = ( int* ) malloc(graph->node_count * sizeof(int));
    }

    for ( int i = 0; i < graph->node_count; i++ ) {
        for ( int j = 0; j < graph->node_count; j++ ) {
            graph->adj[i][j] = 0;
        }
    }

    EXIT_FUNC();
    return graph;
}

void
populate_graph(struct Graph* graph, struct Edge* edges, int edge_count) {
    ENTER_FUNC();
    graph->edge_count = edge_count;

    graph->edges =
        ( struct Edge* ) malloc(graph->edge_count * sizeof(struct Edge));

    memcpy(graph->edges, edges, edge_count * sizeof(struct Edge));

    for ( int i = 0; i < edge_count; i++ ) {
        printf("%d%d%d\n", graph->edges[i].start, graph->edges[i].end,
               graph->edges[i].weight);

        graph->adj[graph->edges[i].start][graph->edges[i].end] =
            graph->edges[i].weight;
        graph->adj[graph->edges[i].end][graph->edges[i].start] =
            graph->edges[i].weight;
    }
    EXIT_FUNC();
}

void
edge_sort(struct Graph* graph) {
    ENTER_FUNC();

    for ( int i = 0; i < graph->edge_count; i++ ) {
        for ( int j = 0; j < graph->edge_count - i; j++ ) {
            if ( graph->edges[j].weight > graph->edges[j + 1].weight ) {
                EDGESWAP(graph->edges[j], graph->edges[j + 1]);
            }
        }
    }

    EXIT_FUNC();
}

void
mst_kruskal(struct Graph* graph) {
    ENTER_FUNC();
    int** final = ( int** ) malloc(graph->node_count * sizeof(int*));

    for ( int i = 0; i < graph->node_count; i++ ) {
        final[i] = ( int* ) malloc(graph->node_count * sizeof(int));
    }

    memcpy(final, graph->adj,
           graph->node_count * graph->node_count * sizeof(int));

    print_matrix(final, graph->node_count);

    int* vertices = ( int* ) malloc(graph->node_count * sizeof(int));

    for ( int i = 0; i < graph->node_count; i++ ) {
        vertices[i] = -1;
    }

    for ( int i = 0; i < graph->node_count; i++ ) {
        printf("%d ", vertices[i]);
    }

    fprintf(stdout, "%d %d %d", graph->edges[0].start, graph->edges[0].end,
            graph->edges[0].weight);

    EXIT_FUNC();
}