//how to code BFS(queue)
// #include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//maximum number of nodes in the graph. Here, we have taken a large value for convenience
const int N=1e5+2;
bool vis[N];
vector<int> adj[N];

void dfs(int node)
{
    //preorder
    vis[node]=1;
    cout<<node<<" ";
    //inorder   cout<<node<<" ";
    //checking wether nodes are visited or not
    vector<int>::iterator it;
    for(it=adj[node].begin(); it!=adj[node].end();it++)
    {
        if (!vis[*it]);
        else
        {
            // If the adjacent node is not visited, recursively call dfs on it
            dfs(*it);
        }
    }
    //postorder
}
int main()
{
    for(int i=0;i<N;i++)
    vis[i]=false;
    //Taking input of nodes and edges
    int n,m;
    cin>>n>>m;

    int x,y;
    for(int i =0;i<m;i++)
{
    cin>>x>>y;// Taking input of edges (x, y)
    adj[x].push_back(y);// Adding edge (x, y)

    adj[y].push_back(x);// Adding edge (y, x) for an undirected graph
    
}

    dfs(1);// Starting DFS from node 1
    return 0;
}

/*output:1 2 3 4 5 6 7
