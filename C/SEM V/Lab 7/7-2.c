// 7-2. Write a program to implement Depth-First Search on a Graph

// Included Libraries
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Memory operations
#include <string.h>  // Memcpy

// Macro Definitions
#define PRINT_ZEROS    0  // Print zeros to show no edge in adjacency matrix
#define PRINT_BLANKS   1  // Print blanks to show no edge in adjacency matrix
#define NODE_COUNT_STR argv[1]  // Command line argument for number of nodes
#define EDGE_COUNT_STR argv[2]  // Command line argument for number of nodes

/** @brief Structure to implement a graph edge */
struct Edge {
    int start;   // Source Node of edge
    int end;     // Destination Node of edge
    int weight;  // Weight/Cost of edge
};

/** @brief Structure to implement a graph data structure */
struct Graph {
    int          node_count;  // Number of nodes in graph
    int          edge_count;  // Number of edges in graph
    struct Edge* edges;       // Array holding all edges associated with graph
    int**        adj;         // Adjacency matrix of graph
};

/**
 * @brief Prints a specified square matrix
 * @param matrix Square matrix to be printed
 * @param len length of @p matrix
 * @endcode
 */
void          print_matrix(int** matrix, int const len);
/**
 * @brief Prints all edges of a specified graph
 * @param graph Graph whose edges are to be printed
 */
void          print_edges(struct Graph const* graph);
/**
 * @brief Initializes the graph data structure with @p node_count nodes
 * @param node_count Number of nodes of the graph
 * @return Graph with @p node_count nodes and no edges
 */
struct Graph* graph_init(int const node_count);
/**
 * @brief Populates the @p graph using the @p edges between the nodes
 * @param graph Graph to be populated
 * @param edges Collection of edges to be added to @p graph
 * @param edge_count Number of @p edges to be added
 */
void          populate_graph(struct Graph*      graph,
                             struct Edge const* edges,
                             int const          edge_count);

int
main(int argc, char** argv) {
    // If no nodes are mentioned, skip execution of program
    if ( argc != 3 ) {
        return 0;
    }

    // Initialize and populate graph
    struct Graph*     graph   = graph_init(atoi(NODE_COUNT_STR));
    struct Edge const edges[] = {
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

    fprintf(stdout, "Adjacency Matrix of Graph:\n");
    print_matrix(graph->adj, graph->node_count);

    fprintf(stdout, "Edges:\n");
    print_edges(graph);

    return 0;
}

void
print_matrix(int** matrix, int const len) {
    fprintf(stdout, "+");

    for ( int i = -2; i < len; i++ ) {
        if ( i == -1 ) {
            fprintf(stdout, "+");
        } else {
            fprintf(stdout, "---");
        }
    }

    fprintf(stdout, "+\n|   |");

    for ( int i = 0; i < len; i++ ) {
        fprintf(stdout, "%2d ", i);
    }

    fprintf(stdout, "|\n+");

    for ( int i = -2; i < len; i++ ) {
        if ( i == -1 ) {
            fprintf(stdout, "+");
        } else {
            fprintf(stdout, "---");
        }
    }

    fprintf(stdout, "+\n|");

    for ( int i = 0; i < len; i++ ) {
        for ( int j = -2; j < len; j++ ) {
            if ( j == -2 ) {
                fprintf(stdout, "%2d ", i);
                continue;
            } else if ( j == -1 ) {
                fprintf(stdout, "|");
                continue;
            }

            if ( matrix[i][j] == 0 ) {
                if ( PRINT_BLANKS ) {
                    fprintf(stdout, "   ");
                } else if ( PRINT_ZEROS ) {
                    fprintf(stdout, "%2d ", matrix[i][j]);
                }
            } else {
                fprintf(stdout, "%2d ", matrix[i][j]);
            }
        }

        fprintf(stdout, "|\n|");
    }

    fprintf(stdout, "\b+");

    for ( int i = -2; i < len; i++ ) {
        if ( i == -1 ) {
            fprintf(stdout, "+");
        } else {
            fprintf(stdout, "---");
        }
    }

    fprintf(stdout, "+\n");
}

void
print_edges(struct Graph const* graph) {
    for ( int i = 0; i < graph->edge_count; i++ ) {
        fprintf(stdout, "%d--%d-->%d\n", graph->edges[i].start,
                graph->edges[i].weight, graph->edges[i].end);
    }
}

struct Graph*
graph_init(int const node_count) {
    // Allocate and define an empty graph with only nodes and no edges
    struct Graph* graph = ( struct Graph* ) malloc(sizeof(struct Graph));
    graph->node_count   = node_count;
    graph->edge_count   = 0;
    graph->edges        = NULL;
    graph->adj          = ( int** ) malloc(graph->node_count * sizeof(int*));

    for ( int i = 0; i < graph->node_count; i++ ) {
        graph->adj[i] =
            ( int* ) malloc(( size_t ) graph->node_count * sizeof(int));
    }

    for ( int i = 0; i < graph->node_count; i++ ) {
        for ( int j = 0; j < graph->node_count; j++ ) {
            graph->adj[i][j] = 0;
        }
    }

    return graph;
}

void
populate_graph(struct Graph*      graph,
               struct Edge const* edges,
               int const          edge_count) {
    // Copy the edges to be a part of the graph object, and then add the edges
    // to the graph by updating the adjacency matrix
    graph->edge_count = edge_count;

    graph->edges =
        ( struct Edge* ) malloc(graph->edge_count * sizeof(struct Edge));

    memcpy(graph->edges, edges, edge_count * sizeof(struct Edge));

    for ( int i = 0; i < edge_count; i++ ) {
        graph->adj[graph->edges[i].start][graph->edges[i].end] =
            graph->edges[i].weight;
        graph->adj[graph->edges[i].end][graph->edges[i].start] =
            graph->edges[i].weight;
    }
}