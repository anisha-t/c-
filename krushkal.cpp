/*This code implements Kruskal's algorithm to find the minimum spanning tree of a given graph. Here's a brief explanation of the code:

1. The code starts by defining constants and including the necessary headers.

2. The `make_set` function initializes each node as a separate set, where the parent of the node is itself and the subtree size is set to 1.

3. The `find_set` function performs path compression while finding the root of the set that a node belongs to. It returns the root node.

4. The `union_sets` function merges two sets by size. It finds the roots of the sets containing the given nodes and performs the union operation by updating the parent and subtree size.

5. In the `main` function, the nodes are initialized as separate sets using `make_set`.

6. The number of nodes and edges are read from the input.

7. Edges are read from the input and stored in a vector, `edges`, along with their weights.

8. The edges are sorted in non-decreasing order based on their weights.

9. The total cost of the minimum spanning tree is initialized to 0.

10. The code iterates over the sorted edges. For each edge, it checks if the source and destination nodes belong to the same set (using `find_set`). If they don't, it means adding this edge to the minimum spanning tree won't create a cycle. Hence, the edge is included in the minimum spanning tree by printing it and updating the cost. The sets of the source and destination nodes are merged using `union_sets`.

11. Finally, the total cost of the minimum spanning tree is printed.

The code uses the disjoint-set data structure (implemented through `make_set`, `find_set`, and `union_sets`) to efficiently determine connectivity and avoid cycles while constructing the minimum spanning tree using Kruskal's algorithm.
*/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;  // Maximum number of nodes in the graph

vector<int> parent(N);  // Parent array to store the parent of each node
vector<int> sz(N);      // Size array to store the size of each set/subtree

void make_set(int v) {
    parent[v] = v;  // Initialize the parent of node v as itself
    sz[v] = 1;      // Initialize the size of the subtree rooted at node v as 1
}

int find_set(int v) {
    if (v == parent[v])  // If v is the parent of itself, it is the root of the set
        return v;
    // Path compression: Set the parent of v to the root of its set and return the root
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);  // Find the root of the set containing node a
    b = find_set(b);  // Find the root of the set containing node b

    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);  // Swap a and b to ensure that the smaller set is always merged into the larger set

        parent[b] = a;      // Make the root of b's set point to the root of a's set
        sz[a] += sz[b];     // Update the size of the set rooted at a
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        make_set(i); // Initialize each node as a separate set
    }
    
    // KRUSKAL'S Algorithm:
    int n, m;
    cin >> n >> m; // Read the number of nodes (n) and edges (m)

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w; // Read an edge (u, v) with weight w
        edges.push_back({w, u, v}); // Store the edge in the vector of edges
    }
    
    sort(edges.begin(), edges.end()); // Sort the edges based on their weights in non-decreasing order

    int cost = 0; // Initialize the total cost of the minimum spanning tree

    for (auto i : edges) {
        int w = i[0]; // Weight of the current edge
        int u = i[1]; // Source vertex of the current edge
        int v = i[2]; // Destination vertex of the current edge
        
        int x = find_set(u); // Find the set that u belongs to
        int y = find_set(v); // Find the set that v belongs to

        if (x == y) {
            continue; // Skip this edge since it will create a cycle in the minimum spanning tree
        } else {
            cout << u << " " << v << "\n"; // Print the edge in the minimum spanning tree
            cost += w; // Add the weight of this edge to the total cost
            union_sets(u, v); // Merge the sets of u and v
        }
    }

    cout << cost; // Print the total cost of the minimum spanning tree

    return 0;
}
