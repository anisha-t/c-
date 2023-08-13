//Algorithm : The algorithm repeats these steps until the queue becomes empty, meaning all the nodes have been processed.
// At each iteration, a node is popped from the queue, its value is printed, and its adjacent nodes' in-degrees are decremented.
// If any adjacent node's in-degree becomes zero, it is added to the queue for further processing.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //taking vertex and edges input
    int n,m;
    cin>>n>>m;
    int cnt=0;//count variable
    //making adjancency list
    vector<vector<int>> adj(n);
    //making vector for indegree
    vector<int> indeg(n,0);
    for(int i =0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //u->v
        adj[u].push_back(v);
        indeg[v]++;
    }

    //pushing those queue in answer whose n degree is 0
       queue<int> qp;
       for (int i = 0 ; i < n ; i++)
    {
        if(indeg[i]==0)
        {
            qp.push(i);
        }
    }
    //Until queue is empty
    while (!qp.empty())
    {
       cnt ++;//increments a counter variable cnt, which keeps track of the number of elements processed or printed during the sorting.
       int x = qp.front();
       qp.pop();
       cout<<x<<" ";
       //x --> v;
       //This line starts a loop that iterates over each element it in the adjacency list of node x. 
       //adj is assumed to be a container (e.g., vector, list) that holds the adjacency lists for all the node
       for(auto it:adj[x])
       {
        //This line decrements the in-degree (incoming edge count) of node it since it is being processed.
        indeg[it]--;
        //This line checks if the in-degree of node it has become zero after decrementing.
        // If it is zero, it means all its incoming edges have been processed, and the node can be added to the queue for further processing.
        if(indeg[it]==0)
        //This line adds the node it to the queue pq since its in-degree has become zero.
        qp.push(it);
       }
    }
    
    return 0;
}
/*OUTPUT:
//input:4 3
0 1
1 2
2 3
//output:
0 1 2 3
*/