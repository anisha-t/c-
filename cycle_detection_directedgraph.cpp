//To detect cycle in an undirected graph

// This code uses depth-first search (DFS) to detect cycles in an undirected graph.
// It takes input for the number of vertices and edges, and constructs an adjacency list representation of the graph.
// Then, it performs DFS on each unvisited node and checks for cycles using a recursive function.
// If a cycle is found, it sets a flag indicating the presence of a cycle. Finally, it outputs whether a cycle is present or not.

#include <bits/stdc++.h>
using namespace std;

bool iscycle(int src,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&stack)
{
    stack[src]=true; // Mark the source node as visited by setting stack[src] to true.
    if(!visited[src]) // If the source node is not visited yet, proceed.
    {
        visited[src]=true; // Mark the source node as visited.
        for(auto i:adj[src]) // Iterate through all the adjacent nodes of the source node.
        {
            if(!visited[i] and iscycle(i,adj,visited,stack)){ // If the adjacent node is not visited and there is a cycle in its subtree, return true.
                return true;
            }
            if(stack[i]) // If the adjacent node is already visited and present in the current recursion stack, return true (cycle is detected).
            return true;
        }
    }
    stack[src]=false; // Set stack[src] to false when backtracking (removing the node from the recursion stack).
    return false; // If no cycle is found in the current DFS traversal, return false.
}


int main()
{
    //taking vertex and edges input
    int n,m;
    cin>>n>>m;
    int cnt=0;//count variable
    //making adjancency list
    vector<vector<int>> adj(n);
    //making vector for indegree
    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //u->v
        adj[u].push_back(v);
    }
    bool cycle=false;
    //stack and visited array
    vector<int>stack(n,0);
    vector<bool>visited(n,0);
    for(int i =0;i<n;i++)
    {
        if(!visited[i] and iscycle(i,adj,visited,stack))
        {
            cycle=true;
        }
    }
        if(cycle)
    {
        cout<<"Cycle is present"<<endl;
    }
    else{
        cout<<" Cycle is not Present "<<endl;
    }
    return 0;
}
/*OUTPUT:
4 3
1 2
2 3
3 1
Cycle is present
*/