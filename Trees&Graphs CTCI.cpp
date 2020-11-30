#include<iostream>
#include<vector>
#include<conio.h>
#include<list>

using namespace::std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// A utility function to do DFS of graph 
// recursively from a given vertex u. 
void DFSUtil(int u, vector<int> adj[],
    vector<bool>& visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFSUtil(adj[u][i], adj, visited);
}

// This function does DFSUtil() for all  
// unvisited vertices. 
void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u = 0; u < V; u++)
        if (visited[u] == false)
            DFSUtil(u, adj, visited);
}


void binary_search(vector<int> &arr , int l , int r)
{
    vector<int>arr{ 1,2,3,4,5,6,7,8,9 };
    int partion = l + r / 2;
    cout << arr[partion];   //top node
    //left node
    binary_search(arr, l, partion - 1);
    //right node
    binary_search(arr, partion + 1, r);
}

// Driver code 
int main()
{
    int V = 5;

    // The below line may not work on all 
    // compilers.  If it does not work on 
    // your compiler, please replace it with 
    // following 
    vector<int> *adj = new vector<int>[V]; 
    // Vertex numbers should be from 0 to 4. 
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    DFS(adj, V);
    return 0;
}