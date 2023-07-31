 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfsTraversal; // Vector to store the BFS traversal
        vector<bool> visited(V, false); // Track visited nodes
        queue<int> q; // Queue for BFS traversal

        // Assuming the BFS starts from node 0, you can modify the starting node as needed
        int startNode = 0;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            bfsTraversal.push_back(currentNode);

            for (int neighbor : adj[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return bfsTraversal;
    }