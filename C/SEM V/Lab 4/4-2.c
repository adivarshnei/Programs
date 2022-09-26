// 4-2. Write a program to implement Prim's Algorithm

// Included Libraries
#include <limits.h>  // INT_MAX
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Memory operations and atoi()
#include <string.h>  // memcpy()

// Macro Definitions
#define NOT_FOUND      -1  // Element not found in set
#define PRINT_BLANKS   1   // Print blanks to show no edge in adjacency matrix
#define PRINT_ZEROS    0   // Print zeros to show no edge in adjacency matrix
#define NODE_COUNT_STR argv[1]  // Command line argument for number of nodes
#define EDGE_COUNT_STR argv[2]  // Command line argument for number of edges
#define ROOT_STR       argv[3]  // Command line argument for root node

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

/** @brief Structure to implement a graph vertex */
struct Vertex {
    int vertex;   // Name of the current vertex
    int key;      // Key value of the current vertex
    int parent;   // Parent of the current vertex
    int in_list;  // Whether the vertex is in the vertices list
};

/**
 * @brief Prints a specified square matrix
 * @param matrix Square matrix to be printed
 * @param len Length of @p matrix
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
/**
 * @brief Extracts the minimum vertex from @p vertices
 * @param vertices Vertex array from which minimum vertex is extracted
 * @param len Length of @p vertices
 * @return Minimum vertex from @p vertices
 */
int           vertex_extract_min(struct Vertex const* vertices, int const len);
/**
 * @brief Finds the minimum spanning tree of the @p graph using Prim's algorithm
 * @param graph Graph whose minimum spanning tree is to be found
 */
void          mst_prim(struct Graph const* graph, struct Vertex const* root);

int
main(int argc, char** argv) {
    // If no nodes or edges are mentioned, skip execution of program
    if ( argc != 4 ) {
        return 0;
    }

    // Initialize and populate graph
    struct Graph*     graph = graph_init(atoi(NODE_COUNT_STR));
    struct Vertex*    root  = ( struct Vertex* ) malloc(sizeof(struct Vertex));
    const struct Edge edges[] = {
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

    // Initialize root vertex
    root->vertex = atoi(ROOT_STR);
    root->parent = -1;
    root->key    = INT_MAX;

    // Execute Prim's Algorithm and print Minimum Spanning Tree
    mst_prim(graph, root);

    {  // Free memory occupied by graph
        free(graph->edges);

        for ( int i = 0; i < graph->edge_count; i++ ) {
            free(graph->adj[i]);
        }

        free(graph->adj);
        free(graph);
        free(root);
    }

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
    graph->adj = ( int** ) malloc(( size_t ) graph->node_count * sizeof(int*));
    graph->edge_count = 0;
    graph->edges      = NULL;

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

    graph->edges = ( struct Edge* ) malloc(( size_t ) graph->edge_count *
                                           sizeof(struct Edge));

    memcpy(graph->edges, edges, ( size_t ) edge_count * sizeof(struct Edge));

    for ( int i = 0; i < edge_count; i++ ) {
        graph->adj[graph->edges[i].start][graph->edges[i].end] =
            graph->edges[i].weight;
        graph->adj[graph->edges[i].end][graph->edges[i].start] =
            graph->edges[i].weight;
    }
}

int
vertex_extract_min(struct Vertex const* vertices, int const len) {
    struct Vertex min_vertex;
    int           min_vertex_index = -1;

    min_vertex.key = INT_MAX;

    for ( int i = 0; i < len; i++ ) {
        if ( vertices[i].in_list == 1 ) {
            if ( min_vertex.key > vertices[i].key ) {
                min_vertex       = vertices[i];
                min_vertex_index = i;
            }
        }
    }

    return min_vertex_index;
}

void
mst_prim(struct Graph const* graph, struct Vertex const* root) {
    // Allocate an empty adjacency matrix to represent an empty minimum spanning
    // tree
    int** min_span_tree =
        ( int** ) malloc(( size_t ) graph->node_count * sizeof(int*));

    for ( int i = 0; i < graph->node_count; i++ ) {
        min_span_tree[i] =
            ( int* ) malloc(( size_t ) graph->node_count * sizeof(int));

        for ( int j = 0; j < graph->node_count; j++ ) {
            min_span_tree[i][j] = 0;
        }
    }

    // Create list of vertices from which minimum is extracted
    int            vertex_u_index;
    struct Vertex* vertices = ( struct Vertex* ) malloc(
        ( size_t ) graph->node_count * sizeof(struct Vertex));

    for ( int i = 0; i < graph->node_count; i++ ) {
        vertices[i].vertex  = i;
        vertices[i].key     = INT_MAX;
        vertices[i].parent  = -1;
        vertices[i].in_list = 1;
    }

    vertices[root->vertex].key = 0;

    // Iterate through the vertices in the list, and keep updating the keys of
    // the vertices which are adjacent to be lower, and update the parent of the
    // vertices accordingly. Do until all the vertices in the list are iterated
    // through. Then use the parents of the vertices to make the Minimum
    // Spanning Tree.
    while ( (vertex_u_index =
                 vertex_extract_min(vertices, graph->node_count)) != -1 ) {
        fprintf(stdout, "\nVertex under examination: (Name: %2d, Key: %2d, ",
                vertices[vertex_u_index].vertex, vertices[vertex_u_index].key);

        if ( vertices[vertex_u_index].parent == -1 ) {
            fprintf(stdout, "Parent:  NULL)\n");
        } else {
            fprintf(stdout, "Parent: %2d)\n", vertices[vertex_u_index].parent);
        }

        fprintf(stdout, "Neighbours of %d: ", vertex_u_index);

        for ( int i = 0; i < graph->node_count; i++ ) {
            if ( graph->adj[i][vertex_u_index] != 0 ) {
                fprintf(stdout, "%d ", i);
            }
        }

        fprintf(stdout, "\n");

        for ( int i = 0; i < graph->node_count; i++ ) {
            if ( graph->adj[vertices[vertex_u_index].vertex][i] != 0 ) {
                int weight_u_v = graph->adj[vertices[vertex_u_index].vertex][i];

                if ( vertices[i].key > weight_u_v &&
                     vertices[i].in_list == 1 ) {
                    vertices[i].parent = vertices[vertex_u_index].vertex;
                    vertices[i].key    = weight_u_v;

                    fprintf(
                        stdout,
                        "Vertex Updated: (Name: %2d, Key: %2d, Parent: %2d)\n",
                        vertices[i].vertex, vertices[i].key,
                        vertices[i].parent);
                }

                vertices[vertex_u_index].in_list = 0;
            }
        }
    }

    fprintf(stdout, "\nFinal Vertices:\n");

    for ( int i = 0; i < graph->node_count; i++ ) {
        fprintf(stdout, "Name: %2d, Key: %2d, ", vertices[i].vertex,
                vertices[i].key);

        if ( vertices[i].parent == -1 ) {
            fprintf(stdout, "Parent:  NULL\n");
        } else {
            fprintf(stdout, "Parent: %2d\n", vertices[i].parent);
        }
    }

    int sum = 0;

    for ( int i = 0; i < graph->node_count; i++ ) {
        sum += vertices[i].key;
    }

    for ( int i = 0; i < graph->node_count; i++ ) {
        if ( vertices[i].parent != -1 ) {
            min_span_tree[vertices[i].vertex][vertices[i].parent] =
                graph->adj[vertices[i].vertex][vertices[i].parent];
            min_span_tree[vertices[i].parent][vertices[i].vertex] =
                graph->adj[vertices[i].parent][vertices[i].vertex];
        }
    }

    fprintf(stdout, "\nAdjacency Matrix of Minimum Spanning Tree:\n");

    print_matrix(min_span_tree, graph->node_count);

    fprintf(stdout, "Sum: %d", sum);

    for ( int i = 0; i < graph->node_count; i++ ) {
        free(min_span_tree[i]);
    }

    free(min_span_tree);
    free(vertices);
}
