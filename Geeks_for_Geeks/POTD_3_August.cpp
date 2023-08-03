class Solution {
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(N);

        // Step 1: Create the graph from the given edges.
        for (const vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            graph[u].emplace_back(v, weight);
        }

        // Step 2: Implement Dijkstra's algorithm to find the shortest path from the source (0) to all other vertices.
        vector<int> distance(N, INT_MAX);
        distance[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int currVertex = pq.top().second;
            int currDistance = pq.top().first;
            pq.pop();

            if (currDistance > distance[currVertex]) continue; // Skip if the distance is not updated

            for (const pair<int, int>& neighbor : graph[currVertex]) {
                int nextVertex = neighbor.first;
                int edgeWeight = neighbor.second;

                if (currDistance + edgeWeight < distance[nextVertex]) {
                    distance[nextVertex] = currDistance + edgeWeight;
                    pq.push({distance[nextVertex], nextVertex});
                }
            }
        }

        // Step 3: Handle vertices that are unreachable from the source.
        for (int i = 0; i < N; ++i) {
            if (distance[i] == INT_MAX) {
                distance[i] = -1;
            }
        }

        return distance;
    }
};