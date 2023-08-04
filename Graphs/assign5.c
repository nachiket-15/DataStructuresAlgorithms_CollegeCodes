#include<stdlib.h>
#include<stdio.h>
#define SIZE 100
FILE*fpointer;

typedef struct Node{
    int numVertices;
    int adjacencyMatrix[SIZE][SIZE];
}Graph;


Graph*creategraph(int numVertices){
    Graph*graph=(Graph*)malloc(sizeof(Graph));
    graph->numVertices=numVertices;
    int i,j;
    for(i=0;i<numVertices;i++){
        for(j=0;j<numVertices;j++){
            graph->adjacencyMatrix[i][j]=0;
        }
    }

    return graph;
}

void addEdge(Graph*graph,int src,int dest,int wt){
    graph->adjacencyMatrix[src][dest]=wt;
    graph->adjacencyMatrix[dest][src]=wt;
}


void init(Graph*graph,int numNodes){
    for(int i=0;i<numNodes+1;i++){
        int src,dest,wt;
        fscanf(fpointer,"%d ",&src);
        fscanf(fpointer,"%d ",&dest);
        fscanf(fpointer,"%d \n",&wt);

        graph->adjacencyMatrix[src][dest]=wt;
        graph->adjacencyMatrix[dest][src]=wt;
    }
}

void printGraph(Graph*graph){
    int i,j;
    printf("\nCurrent graph is as (Adj Matrix Representation ): \n\n");

    for(i=0;i<graph->numVertices;i++){
        for(j=0;j<graph->numVertices;j++){
            printf("%d ",graph->adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

}

int displayDegree(Graph*graph,int node){
    //For degree of zero , we traverse [0][0] to [i][0]... That is first row and check for non non zero elements
    int count=0;
    int j=node;
    for(int i=0;i<=graph->numVertices;i++){
            if(graph->adjacencyMatrix[i][j]!=0){
                count++;
            }
    }
    return count;
}

void displayDegreeAll(Graph*graph){
    for(int i=0;i<graph->numVertices;i++)
        printf("\nThe degree of node %d is %d ",i,displayDegree(graph,i));
    printf("\n");
}

//DFS 


void Dfs(Graph*graph,int src,int visited[]){

    visited[src]=1;
   
    for(int i=0;i<graph->numVertices;i++){
        if((visited[i])==0 && graph->adjacencyMatrix[i][src]!=0){
            //Recursively call dfs
            Dfs(graph,i,visited);
        }
    }
}




int isConnected(Graph*graph){
    //Initialize visited array 
    int visited[SIZE]={0};
    // Call for dfs
    Dfs(graph,0,visited);

    for(int i=0;i<graph->numVertices;i++){
        if(visited[i]==0){
            return 0;
        }
    }
    return 1;
}

void isConnectedStatus(Graph*graph){
    printf("\n");
    int ans=isConnected(graph);
    if(ans){
        printf("Graph is connected");
    }
    else{
        printf("Graph is not connected");
    }
    printf("\n");
}

void AdjacencyCheck(Graph*graph,int vertex1,int vertex2){
    if(graph->adjacencyMatrix[vertex1][vertex2]!=0){
        printf("\n%d & %d are adjacent",vertex1,vertex2);
    }
    else{
        printf("\n%d & %d are not adjacent",vertex1,vertex2);
    }

}
void Dfs_for_count(Graph*graph,int src,int visited[],int componentVertices[],int *vertex_count){
    
    visited[src]=1;
    componentVertices[*vertex_count]=src;
    (*vertex_count)++;

    for(int i=0;i<graph->numVertices;i++){
        if((visited[i])==0 && graph->adjacencyMatrix[i][src]!=0){
            //Recursively call dfs
            Dfs_for_count(graph,i,visited,componentVertices,vertex_count);
        }
    }
}
void no_of_components(Graph*graph,int numNodes){
    int visited[SIZE]={0};

    int count=0; 
    int vertex_count=0;
    
    int componentVertices[SIZE];
    printf("\n");

    for(int i=0;i<numNodes;i++){
        if(!visited[i]){
            count++;
            Dfs_for_count(graph,i,visited,componentVertices,&vertex_count);

            printf("Component %d : ", count);
            for (int j = i; j < vertex_count; j++) {
                printf("%d ", componentVertices[j]);
            }
            printf("\n");

        }
    }
    printf("\nThe no of components in this graph are %d \n",count);
}

//cycle
void DFS(Graph* graph, int v, int* visited, int* path, int pathLength) {
    visited[v] = 1;
    path[pathLength] = v;

    int i;
    for (i = 0; i < graph->numVertices; i++) {
        if (graph->adjacencyMatrix[v][i]) {
            if (!visited[i]) {
                // Recursively explore the adjacent vertices
                DFS(graph, i, visited, path, pathLength + 1);
            } else if (i == path[0] && pathLength >= 2) {
                // Found a cycle that ends at the starting vertex
                printf("Cycle found: ");
                int j;
                for (j = 0; j <= pathLength; j++) {
                    printf("%d ", path[j]);
                }
                printf("\n");
            }
        }
    }

    // Reset the visited flag for the current vertex
    visited[v] = 0;
}

void printCycles(Graph* graph) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    int* path = (int*)calloc(graph->numVertices, sizeof(int));

    int i;
    for (i = 0; i < graph->numVertices; i++) {
        DFS(graph, i, visited, path, 0);
    }

    free(visited);
    free(path);
}



int main(){
    int numNodes;

    
    fpointer=fopen("file.txt","r");
    if(fpointer==NULL){
        printf("File was not created");
    }

    fscanf(fpointer,"%d\n",&numNodes);
    
    Graph*graph=creategraph(numNodes);

    init(graph,numNodes);
    
    // Print the graph
    printGraph(graph);
    displayDegreeAll(graph);

    isConnectedStatus(graph);
    
    AdjacencyCheck(graph,0,1);
    AdjacencyCheck(graph,0,3);
    printf("\n");

    no_of_components(graph,numNodes);
    printCycles(graph);
    
    // detectCycles(graph)
    return 0;
}