

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[] , int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}



int main()
{
    int V = 5;
    
    vector<int> adj[V]; // adjacency list
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 

    for(int i = 0 ; i <V ;i++)
    {
        cout << i <<":";
        for(auto i : adj[i])
            cout << "->" << i;
        cout << endl;
    }

    return 0;
}