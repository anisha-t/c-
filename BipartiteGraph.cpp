#include<bits/stdc++.h>
using namespace std;
//adjacency list of graph
vector<vector<int>>adj;
vector<bool>vist;
vector<int>col;
bool bipart;
//Giving color
void color(int u,int curr)
{
    if(col[u]!=-1and col[u]!=curr)
    {
        bipart=false;
        return;
    }
    col[u]=curr;
    if(vis[u])
    return;
    vist[u]=true;
}
int main()
{
    //taking vertex and edges input
    int n,m;
    cin>>n>>m;
    int cnt=0;//count variable
    //making adjancency list
    adj=vector<vector<int>>(n);
    vist=vector<bool>(n,false);
    col=vector<int>(n,-1);
    //making vector for indegree
    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //u->v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
  
    /*Iterating through all vertices of adjacency matrix*/
    for(int i=0;i<n;i++)
    {
        if (!vist[i])
        {
           color(i,0);
        }
        
    }
    if(bipart)
    {
        cout<<"Graph is bipartite"<<endl;
    }
    else{
        cout<<"Graph is  not bipartite  "<<endl;
    }
    return 0;
}
