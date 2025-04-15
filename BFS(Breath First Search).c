#include <stdio.h>
#include <stdlib.h>


struct Graph {
    int V; 
    int **adjMatrix;  
};


struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

   
    graph->adjMatrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->adjMatrix[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;  
        }
    }
    return graph;
}

// Function to add an edge to the graph (undirected graph)
void addEdge(struct Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;  // Since the graph is undirected
}

// Function to perform BFS traversal starting from a source vertex
void BFS(struct Graph* graph, int startVertex) {
    int *visited = (int*)malloc(graph->V * sizeof(int));  // Array to track visited vertices
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;  // Initialize all vertices as unvisited
    }

    
    int *queue = (int*)malloc(graph->V * sizeof(int));
    int front = 0, rear = 0;

   
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);

    while (front != rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        
        for (int i = 0; i < graph->V; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");

   
    free(visited);
    free(queue);
}


int main() {
    int V = 6;  
    struct Graph* graph = createGraph(V);

   
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

   
    BFS(graph, 0);

    
    for (int i = 0; i < V; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);

    return 0;
}
