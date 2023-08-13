//To detect cycle in an undirected graph
#include <bits/stdc++.h>
using namespace std;

//Making function to check wether the cycle is present or not
bool iscycle(int src,vector<vector<int>>&adj,vector<bool>&visited,int parent)
{
    visited[src]=true;//src is true
    //iterating over adjacent list 
    for (auto i : adj[src])
    {
        if(i!=parent)//check if parent is present or not
        if(visited[i])//if visited then true
        return true;
        if (!visited[i] and iscycle(i,adj,visited,src))
        {
            return true;
        }
        
    }
    return false;
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
        adj[v].push_back(u);
    }
    bool cycle=false;
    vector<bool>visited(n,false);
    /*Iterating through all vertices of adjacency matrix*/
    for(int i=0;i<n;i++)
    {
        if (!visited[i] and iscycle(i,adj,visited,-1))
        {
            cycle= true;
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
/*output:
4 3
0 1
1 2
2 0
Cycle is present
4 2
0 1
1 2
Cycle is not present
*/