// 4. Write a program to implement Kruskal's Algorithm

// Included Libraries
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Memory operations and atoi()
#include <string.h>  // memcpy() function

// Macro Definitions
#define NOT_FOUND      -1  // Element not found in set
#define PRINT_BLANKS   1   // Print blanks to show no edge in adjacency matrix
#define PRINT_ZEROS    0   // Print zeros to show no edge in adjacency matrix
#define NODE_COUNT_STR argv[1]  // Command line argument for number of nodes
#define EDGE_COUNT_STR argv[2]  // Command line argument for number of edges
/**
 * @brief Macro to Swap Edges
 * @param A First Edge
 * @param B Second Edge
 */
#define EDGESWAP(A, B)    \
    struct Edge temp = A; \
    A                = B; \
    B                = temp;

/** @brief Structure to implement a set data structure */
struct Set {
    int* data;  // Array storing elements in Set
    int  size;  // Number of elements stored in Set
};

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
 * @brief Searches the @p array for @p query using recursive linear search
 * @param array Array to be searched
 * @param len Length of @p array
 * @param query Element to be searched for
 * @param loc Location currently being searched for
 * @return Location where element is found
 */
int           linear_search(int const* array,
                            int const  len,
                            int const  query,
                            int const  loc);
/**
 * @brief Initializes the set data structure with elements in @p array
 * @param array Array of elements being input to the set
 * @param len Length of @p array
 * @return Set containing elements in @p array
 */
struct Set*   set_init(int const* array, int const len);
/**
 * @brief Appends @p element to array
 * @param set Set to which @p element is to be appended
 * @param element Element which is appended to @p set
 */
void          set_append(struct Set* set, int const element);
/**
 * @brief Displays the specified set
 * @param set Set to be displayed
 */
void          set_display(struct Set const* set);
/**
 * @brief Performs union operation on @p set1 and @p set2
 * @param set1 First set
 * @param set2 Second set
 * @return Union of @p set1 and @p set2
 */
struct Set*   set_union(struct Set const* set1, struct Set const* set2);
/**
 * @brief Prints a specified square matrix
 * @param matrix Square matrix to be printed
 * @param len Length of @p matrix
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
 * @brief Sorts the edges in non-decreasing order using bubble sort.
 * @param graph Graph whose edges are to be sorted
 */
void          edge_sort(struct Graph* graph);
/**
 * @brief Finds the minimum spanning tree of the @p graph using Kruskal's
 * algorithm
 * @param graph Graph whose minimum spanning tree is to be found
 */
void          mst_kruskal(struct Graph const* graph);

int
main(int argc, char** argv) {
    // If no nodes or edges are mentioned, skip execution of program
    if ( ! NODE_COUNT_STR || ! EDGE_COUNT_STR || argc != 3 ) {
        return 0;
    }

    // Initialize and populate graph
    struct Graph*     graph   = graph_init(atoi(NODE_COUNT_STR));
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

    edge_sort(graph);

    fprintf(stdout, "Edges: \n");
    print_edges(graph);

    // Execute Prim's Algorithm and print Minimum Spanning Tree
    mst_kruskal(graph);

    {  // Free memory occupied by graph
        free(graph->edges);

        for ( int i = 0; i < graph->edge_count; i++ ) {
            free(graph->adj[i]);
        }

        free(graph->adj);
        free(graph);
    }

    return 0;
}

int
linear_search(int const* array, int const len, int const query, int const loc) {
    if ( loc < 0 ) {  // If the location being searched for goes out of bounds,
                      // this means that the element does not exist
        return NOT_FOUND;
    } else if ( array[loc] == query ) {
        return loc;
    }

    return linear_search(array, len, query, loc - 1);
}

struct Set*
set_init(int const* array, int const len) {
    // Allocate and define an empty set
    struct Set* set = ( struct Set* ) malloc(sizeof(struct Set));
    set->data       = NULL;
    set->size       = 0;

    // If elements are specified in initialization
    if ( array != NULL ) {
        // Allocate and define set elements
        set->data = ( int* ) malloc(sizeof(int));

        for ( int i = 0; i < len; i++ ) {
            set_append(set, array[i]);
        }
    }

    return set;
}

void
set_append(struct Set* set, int const element) {
    // If element does not already exist in set, increase the size of the set,
    // reallocate it to more memory and define it to include the element
    if ( linear_search(set->data, set->size, element, set->size - 1) == -1 ) {
        set->size++;

        set->data = ( int* ) realloc(set->data, set->size * sizeof(int));
        set->data[set->size - 1] = element;
    }
}

void
set_display(struct Set const* set) {
    fprintf(stdout, "%d: ", set->size);

    for ( int i = 0; i < set->size; i++ ) {
        fprintf(stdout, "%d\t", set->data[i]);
    }

    fprintf(stdout, "\n");
}

struct Set*
set_union(struct Set const* set1, struct Set const* set2) {
    // Create result array as duplicate of set1, and then append all elements of
    // set2 to it
    struct Set* result = set_init(set1->data, set1->size);

    for ( int i = 0; i < set2->size; i++ ) {
        set_append(result, set2->data[i]);
    }

    return result;
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

void
edge_sort(struct Graph* graph) {
    for ( int i = 0; i < graph->edge_count; i++ ) {
        for ( int j = 0; j < graph->edge_count - i - 1; j++ ) {
            if ( graph->edges[j].weight > graph->edges[j + 1].weight ) {
                EDGESWAP(graph->edges[j], graph->edges[j + 1]);
            }
        }
    }
}

void
mst_kruskal(struct Graph const* graph) {
    // Allocate an empty adjacency matrix to represent an empty minimum spanning
    // tree
    int** min_span_tree = ( int** ) malloc(graph->node_count * sizeof(int*));
    int   sum           = 0;

    for ( int i = 0; i < graph->node_count; i++ ) {
        min_span_tree[i] = ( int* ) malloc(graph->node_count * sizeof(int));

        for ( int j = 0; j < graph->node_count; j++ ) {
            min_span_tree[i][j] = 0;
        }
    }

    // Create sets for each vertex
    struct Set** vertex_sets =
        ( struct Set** ) malloc(graph->node_count * sizeof(struct Set*));

    for ( int i = 0; i < graph->node_count; i++ ) {
        vertex_sets[i] = set_init(&i, 1);
    }

    fprintf(stdout, "\nVertex Sets: \n");

    for ( int i = 0; i < graph->node_count; i++ ) {
        set_display(vertex_sets[i]);
    }

    // Iterate through the edges. If the endpoints are in different sets, make a
    // union of these sets, and add the edge to the MST. If the endpoints are in
    // the same set, a cycle will be formed, and this edge should be ignored.
    // After all the edges are examined, we get the adjacency matrix of the MST.
    for ( int i = 0; i < graph->edge_count; i++ ) {
        int start     = graph->edges[i].start;
        int end       = graph->edges[i].end;
        int start_set = -1;
        int end_set   = -1;

        fprintf(stdout, "\nEdge Under Consideration: %d--%d-->%d\n",
                graph->edges[i].start, graph->edges[i].weight,
                graph->edges[i].end);

        for ( int j = 0; j < graph->node_count; j++ ) {
            if ( vertex_sets[j] == NULL ) {
                continue;
            }

            start_set =
                (linear_search(vertex_sets[j]->data, vertex_sets[j]->size,
                               start, vertex_sets[j]->size - 1) == -1)
                    ? start_set
                    : j;
            end_set = (linear_search(vertex_sets[j]->data, vertex_sets[j]->size,
                                     end, vertex_sets[j]->size - 1) == -1)
                        ? end_set
                        : j;
        }

        if ( start_set != end_set ) {
            fprintf(stdout,
                    "Sets containing start and end of edge are different, "
                    "performing union\n");
            vertex_sets[start_set] =
                set_union(vertex_sets[start_set], vertex_sets[end_set]);

            vertex_sets[end_set] = NULL;

            min_span_tree[start_set][end_set] = graph->edges[i].weight;
            min_span_tree[end_set][start_set] = graph->edges[i].weight;
        } else {
            fprintf(stdout,
                    "Sets containing start and end are the same, "
                    "continuing\n");
        }

        fprintf(stdout, "\nVertex Sets: \n");

        for ( int j = 0; j < graph->node_count; j++ ) {
            if ( vertex_sets[j] != NULL ) {
                set_display(vertex_sets[j]);
            }
        }
    }

    fprintf(stdout, "\nAdjacency Matrix of Minimum Spanning Tree: \n");

    print_matrix(min_span_tree, graph->node_count);

    for ( int i = 0; i < graph->node_count; i++ ) {
        for ( int j = 0; j < graph->node_count; j++ ) {
            sum += min_span_tree[i][j];
        }
    }

    sum /= 2;

    fprintf(stdout, "Total Weight: %d\n", sum);

    for ( int i = 0; i < graph->node_count; i++ ) {
        free(vertex_sets[i]->data);
        free(vertex_sets[i]);
    }

    free(vertex_sets);

    for ( int i = 0; i < graph->node_count; i++ ) {
        free(min_span_tree[i]);
    }

    free(min_span_tree);
}
