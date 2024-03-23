//Graph representation

//for undirected graph

// Adjacency Matrix
// An adjacency matrix of a graph is a two-dimensional array of size n x n, where n is the number of nodes in the graph, 
// with the property that a[ i ][ j ] = 1 if the edge (vᵢ, vⱼ) is in the set of edges, and a[ i ][ j ] = 0 if there is no such edge.


using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1  // this statement will be removed in case of directed graph
    }
    return 0;
}
//SC:(N*N)

// Adjacency Lists
// In the previous storing method, we saw it was taking n² space to store the graph, this is where the adjacency list comes into the picture, 
// it takes a very less amount of space.

// This is a node-based representation. In this representation, we associate with each node a list of nodes adjacent to it. 
// Normally an array is used to store the nodes. 
// The array provides random access to the adjacency list for any particular node.
//store immediate nodes of all vertices/nodes connected in the vector

// In this representation, for an undirected graph, each edge data appears twice. 
// For example, nodes 1 and 2 are adjacent hence node 2 appears in the list of node 1, and node 1 appears in the list of node 2. 
// So, the space needed to represent an undirected graph using its adjacency list is 2 x E locations, where E denotes the number of edges.

// Space complexity = O(2xE)

#include<iostream>
using namespace std;

int main(){
    int n,e;                       //nodes  //edges
    cin>>n>>e;
    vecor<int>adj(n+1);
    for(int i=0;i<e;i++){
       int u,v;
       adj[u].push_back(v);
       adj[v]=push_back(u);
    }
    return 0;
}


//for directed graphs
// For directed graphs, if there is an edge between u and v it means the edge only goes from u to v, 
// i.e., v is the neighbor of u, but vice versa is not true. 
// The space needed to represent a directed graph using its adjacency list is E locations, 
// where E denotes the number of edges, as here each edge data appears only once.
