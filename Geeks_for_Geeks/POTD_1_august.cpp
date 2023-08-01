    void dfsUtil(int node, vector<int> adj[], vector<bool>& visited, vector<int>& result) {
        visited[node] = true; // Mark the current node as visited.
        result.push_back(node); // Add the current node to the result.

        // Traverse all the adjacent nodes of the current node.
        for (int neighbor : adj[node]) {
            // If the neighbor is not visited, recursively call dfsUtil for it.
            if (!visited[neighbor]) {
                dfsUtil(neighbor, adj, visited, result);
            }
        }
    }

    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<bool> visited(V, false); // Initialize an array to keep track of visited nodes.

        // Loop through all the nodes and perform DFS if not already visited.
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsUtil(i, adj, visited, result);
            }
        }

        return result;
    }
};
In this code, we define a helper function dfsUtil that performs the actual DFS traversal starting from a given node. The main dfsOfGraph function initializes a visited array to keep track of visited nodes and then iterates through all the nodes to perform DFS from each unvisited node. The DFS starts with the first node and recursively explores all its unvisited neighbors.

You can now use the dfsOfGraph function to perform a DFS traversal on your graph. The input graph should be represented using an adjacency list, where V is the number of vertices and adj[] is an array of vectors representing the adjacency list of each vertex. The function will return a vector containing the DFS traversal of the graph.





