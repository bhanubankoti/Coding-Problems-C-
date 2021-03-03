//Depth First Search

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[] , int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(vector<int> adj[] , vector<bool>&visited , int src)
{
    visited[src] = true;
    cout << "->"<<src ; 
    for(auto i =adj[src].begin() ; i != adj[src].end() ; i++)
    {
        if(!visited[*i])
        DFS(adj,visited,*i);
    }
}
int main()
{
    int V = 4;
    
    vector<int> adj[V]; // adjacency list

    addEdge(adj,0, 1);
    addEdge(adj,0, 2);
    addEdge(adj,1, 2);
    addEdge(adj,2, 0);
    addEdge(adj,2, 3);
    addEdge(adj,3, 3);
    vector<bool> visited(V,false);
 
    cout << "Depth First Traversal"
            " (starting from vertex 2) \n";
    DFS(adj,visited,2);
 
    return 0;
}

