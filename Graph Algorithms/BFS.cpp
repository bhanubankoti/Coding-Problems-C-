// Breadth First Search

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[] , int u,int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}

void BFS(vector<int> adj[] , vector<bool>&visited , int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    

    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        cout <<"->" << x;
        for(auto itr = adj[x].begin() ; itr != adj[x].end() ; itr++)
        {
            if(!visited[*itr])
            {
                visited[*itr] = true;
                q.push(*itr);
            }
        }
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
 
    cout << "Breadth First Traversal"
            " (starting from vertex 2) \n";
    BFS(adj,visited,2);
 
    return 0;
}
