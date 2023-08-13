//how to code BFS(queue)
// #include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5 + 2;
bool vis[N];
vector<int> adj[N];

int main()
{
    // Initializing the visited array as false for all nodes
    for (int i = 0; i < N; i++)
        vis[i] = false;

    int n, m;
    cin >> n >> m; // Taking input of the number of nodes (n) and edges (m)

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y; // Taking input of edges (x, y)
        adj[x].push_back(y); // Adding edge (x, y)
        adj[y].push_back(x); // Adding edge (y, x) for an undirected graph
    }

    queue<int> q;
    q.push(1); // Starting from node 1
    vis[1] = true; // Marking node 1 as visited

    while (!q.empty())
    {
        int node = q.front(); // Take the front element from the queue
        q.pop();
        cout << node << endl; // Print the node

        // Checking the adjacent nodes of the current node
        vector<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (!vis[*it]) // If the adjacent node is not visited
            {
                vis[*it] = true; // Mark it as visited
                q.push(*it); // Push it to the queue for further traversal
            }
        }
    }

    return 0;
}


/*input:
7 7 
1 2
1 3
2 4
2 5
2 6
2 7
7 3
output
1
2
3
4
5
6
7
*