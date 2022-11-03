// 7. Write a program to implement Breadth-First Search on a Graph

// Included Libraries
#include <assert.h>  // assert()
#include <limits.h>  // INT_MAX
#include <stdio.h>   // IO and other operations
#include <stdlib.h>  // Memory operations
#include <string.h>  // memcpy()

// Macro Definitions
#define PRINT_ZEROS    0  // Print zeros to show no edge in adjacency matrix
#define PRINT_BLANKS   1  // Print blanks to show no edge in adjacency matrix
#define NODE_COUNT_STR argv[1]  // Command line argument for number of nodes
#define EDGE_COUNT_STR argv[2]  // Command line argument for number of nodes

/** @brief Available vertex colors */
enum Color {
    WHITE = 1,
    GRAY  = 2,
    BLACK = 3
};

/** @brief Structure to implement a graph edge */
struct Edge {
    int start;  // Source Node of edge
    int end;    // Destination Node of edge
};

/** @brief Structure to implement a graph vertex */
struct Vertex {
    int            vertex;    // Name of the current vertex
    enum Color     color;     // Color of the current vertex
    int            distance;  // Distance of vertex from source
    struct Vertex* parent;    // Parent of vertex
};

/** @brief Structure to implement a graph data structure */
struct Graph {
    int            node_count;  // Number of nodes in graph
    int            edge_count;  // Number of edges in graph
    struct Edge*   edges;       // Array holding all edges associated with graph
    struct Vertex* vertices;    // Array holding all vertices in graph
    int**          adj;         // Adjacency matrix of graph
};

/** @brief Structure to implement a node in a linked queue */
struct Node {
    struct Vertex* vertex;  // Element at node
    struct Node*   next;    // Link to next node
};

/** @brief Structure to implement a linked queue */
struct Queue {
    struct Node* front;  // Front of queue
    struct Node* rear;   // End of queue
    int          len;    // Length of queue
};

/**
 * @brief Prints a specified square matrix
 * @param matrix Square matrix to be printed
 * @param len length of @p matrix
 */
void           print_matrix(int** matrix, int const len);
/**
 * @brief Prints all edges of a specified graph
 * @param graph Graph whose edges are to be printed
 */
void           print_edges(struct Graph const* graph);
/**
 * @brief Prints all vertices with their colors
 * @param graph Graph whose vertices are to be printed
 */
void           print_vertices(struct Graph const* graph);
/**
 * @brief Initializes a queue
 * @return Empty queue
 */
struct Queue*  queue_init();
/**
 * @brief Enqueue @p vertex to @p queue
 * @param queue Queue to which element is added
 * @param vertex Vertex to enqueue
 */
void           enqueue(struct Queue* queue, struct Vertex* vertex);
/**
 * @brief Dequeue vertex from @p queue and return it
 * @param queue Queue to which element is added
 * @return Dequeued element
 */
struct Vertex* dequeue(struct Queue* queue);
/**
 * @brief Initializes the graph data structure with @p node_count nodes
 * @param node_count Number of nodes of the graph
 * @return Graph with @p node_count nodes and no edges
 */
struct Graph*  graph_init(int const node_count);
/**
 * @brief Clear the memory allocated for graph
 * @param graph Graph to be cleared
 */
void           graph_dealloc(struct Graph* graph);
/**
 * @brief Populates the @p graph using the @p edges between the nodes
 * @param graph Graph to be populated
 * @param edges Collection of edges to be added to @p graph
 * @param edge_count Number of @p edges to be added
 */
void           graph_populate(struct Graph*      graph,
                              struct Edge const* edges,
                              int const          edge_count);
/**
 * @brief Perform Breadth First Search on @p graph
 * @param graph Graph to be searched
 * @param source Node to be used as the source for the search
 */
void breadth_first_search(struct Graph const* graph, int const source);

int
main(int argc, char** argv) {
    // If no nodes are mentioned, skip execution of program
    if ( argc != 3 ) {
        return 0;
    }

    // Initialize and populate graph
    struct Graph*     graph   = graph_init(atoi(NODE_COUNT_STR));
    struct Edge const edges[] = {
        {.start = 0, .end = 1},
        {.start = 0, .end = 7},
        {.start = 1, .end = 2},
        {.start = 1, .end = 7},
        {.start = 2, .end = 3},
        {.start = 3, .end = 4},
        {.start = 3, .end = 5},
        {.start = 4, .end = 5},
        {.start = 5, .end = 6},
        {.start = 6, .end = 7},
        {.start = 6, .end = 8},
        {.start = 7, .end = 8}
    };

    graph_populate(graph, edges, atoi(EDGE_COUNT_STR));

    fprintf(stdout, "Adjacency Matrix of Graph:\n");
    print_matrix(graph->adj, graph->node_count);

    fprintf(stdout, "Edges:\n");
    print_edges(graph);

    breadth_first_search(graph, 0);

    graph_dealloc(graph);

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
        fprintf(stdout, "%d--->%d\n", graph->edges[i].start,
                graph->edges[i].end);
    }
}

void
print_vertices(struct Graph const* graph) {
    for ( int i = 0; i < graph->node_count; i++ ) {
        fprintf(stdout, "Vertex %2d: Color %2d Distance %2d\n",
                graph->vertices[i].vertex, graph->vertices[i].color,
                graph->vertices[i].distance);
    }
}

struct Queue*
queue_init() {
    struct Queue* queue = ( struct Queue* ) malloc(sizeof(struct Queue));
    queue->front        = NULL;
    queue->rear         = NULL;
    queue->len          = 0;

    return queue;
}

void
enqueue(struct Queue* queue, struct Vertex* vertex) {
    struct Node* new_node = ( struct Node* ) malloc(sizeof(struct Node));

    new_node->vertex = vertex;
    new_node->next   = NULL;

    if ( queue->front == NULL ) {
        queue->front = new_node;
        queue->rear  = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear       = new_node;
    }

    queue->len++;
}

struct Vertex*
dequeue(struct Queue* queue) {
    struct Node* temp = ( struct Node* ) malloc(sizeof(struct Node));

    // Quit if queue is empty
    assert(queue->front != NULL);

    struct Vertex* vertex = queue->front->vertex;

    temp         = queue->front;
    queue->front = queue->front->next;

    if ( queue->front == NULL ) {
        queue->rear = NULL;
    }

    free(temp);

    queue->len--;

    return vertex;
}

struct Graph*
graph_init(int const node_count) {
    // Allocate and define an empty graph with only nodes and no edges
    struct Graph* graph = ( struct Graph* ) malloc(sizeof(struct Graph));
    graph->node_count   = node_count;
    graph->edge_count   = 0;
    graph->edges        = NULL;
    graph->adj          = ( int** ) malloc(graph->node_count * sizeof(int*));
    graph->vertices =
        ( struct Vertex* ) malloc(node_count * sizeof(struct Vertex));

    for ( int i = 0; i < graph->node_count; i++ ) {
        graph->adj[i] =
            ( int* ) malloc(( size_t ) graph->node_count * sizeof(int));
        graph->vertices[i].vertex   = i;
        graph->vertices[i].color    = WHITE;
        graph->vertices[i].distance = INT_MAX;
        graph->vertices[i].parent   = NULL;
    }

    for ( int i = 0; i < graph->node_count; i++ ) {
        for ( int j = 0; j < graph->node_count; j++ ) {
            graph->adj[i][j] = 0;
        }
    }

    return graph;
}

void
graph_dealloc(struct Graph* graph) {
    for ( int i = 0; i < graph->node_count; i++ ) {
        free(graph->adj[i]);
    }

    free(graph->adj);
    free(graph->edges);
    free(graph->vertices);
    free(graph);
}

void
graph_populate(struct Graph*      graph,
               struct Edge const* edges,
               int const          edge_count) {
    // Copy the edges to be a part of the graph object, and then add the edges
    // to the graph by updating the adjacency matrix
    graph->edge_count = edge_count;

    graph->edges =
        ( struct Edge* ) malloc(graph->edge_count * sizeof(struct Edge));

    memcpy(graph->edges, edges, edge_count * sizeof(struct Edge));

    for ( int i = 0; i < edge_count; i++ ) {
        graph->adj[graph->edges[i].start][graph->edges[i].end] = 1;
        graph->adj[graph->edges[i].end][graph->edges[i].start] = 1;
    }
}

void
print_queue(struct Queue* queue) {
    struct Node* node = queue->front;

    fprintf(stdout, "%d: ", queue->len);

    while ( node != NULL ) {
        fprintf(stdout, "%d ", node->vertex->vertex);

        node = node->next;
    }

    fprintf(stdout, "\n");
}

void
breadth_first_search(struct Graph const* graph, int const source) {
    // Assign node as source
    graph->vertices[source].color    = GRAY;
    graph->vertices[source].distance = 0;
    graph->vertices[source].parent   = NULL;

    struct Queue* queue = queue_init();
    int* visit_order    = ( int* ) malloc(graph->node_count * sizeof(int));
    int  visit_index    = 0;

    // Add node to queue
    enqueue(queue, &graph->vertices[source]);

    fprintf(stdout, "Queue Status:\n");

    // Until all nodes are encountered, iterate through them using a queue, thus
    // in a breadth wise manner
    while ( queue->len > 0 ) {
        print_queue(queue);
        struct Vertex* u = dequeue(queue);

        for ( int i = 0; i < graph->node_count; i++ ) {
            if ( graph->adj[u->vertex][i] != 0 &&
                 graph->vertices[i].color == WHITE ) {
                graph->vertices[i].color    = GRAY;
                graph->vertices[i].distance = u->distance + 1;
                graph->vertices[i].parent   = u;

                enqueue(queue, &graph->vertices[i]);
            }
        }

        u->color = BLACK;

        visit_order[visit_index++] = u->vertex;
    }

    fprintf(stdout, "\nBreadth First Visit Order:\n");

    for ( int i = 0; i < graph->node_count; i++ ) {
        fprintf(stdout, "%d\t", visit_order[i]);
    }
}
