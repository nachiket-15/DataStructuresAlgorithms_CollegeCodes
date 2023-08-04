#include <iostream>
using namespace std;

// ADJACENCY MATRIX REPRESENTATION FOR GRAPH

int main()
{
    int n;// n is number of nodes
    int m;// m is number of edges

    cin>>n>>m;

    int adjMat[n+1][n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        // For directed graph , adjMat[u][v] will be 1
        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }
    return 0;
}