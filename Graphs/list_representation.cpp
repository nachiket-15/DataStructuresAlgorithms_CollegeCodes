#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<vector<int>> printGraph(vector<int>adj[],int V){

    vector<vector<int>>ans;

    for(int i=0;i<V;i++){

        vector<int>row;
        row.push_back(i);//FIRST PUT INDEX OF ROW
        cout<<i<<" -> ";
        //THEN LOOP TILL SIZE OF THAT PARTICULAR ROW
        //FOR THAT I PUSH VALUES IN OUR ROW VECTOR FOR PRINTING
        for(int j=0;j<adj[i].size();j++){
            row.push_back(adj[i][j]);
            cout<<adj[i][j]<<" ";
            // I IS AS PER OUTER LOOP
            // J IS AS PER INNER LOOP
        }
        //PUT EVERY ROW VECTOR AFTER ITERATION INTO ANS VECTOR
        ans.push_back(row);
        cout<<endl;
    }

    return ans;
}
int main()
{
    int V=5;
    vector<int>adj[5];//It should be adj[V] but VS code not allowing variable in size declaration 
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,1,4);
    addEdge(adj,2,3);
    addEdge(adj,3,4);

    // 0 -- 1 
    //     /    \ 
    // | /  |    2
    //  /      /
    // 4 -- 3 
    //OUR GRAPH

    printGraph(adj,5);
    return 0;
}