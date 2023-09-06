#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    // DFS function to mark visited vertices and track the last finished vertex
    void DFS(int v, vector<int> adj[], vector<bool>& visited) {
        visited[v] = true;
        for(int i = 0; i < adj[v].size(); i++) {
            if(!visited[adj[v][i]]) {
                DFS(adj[v][i], adj, visited);
            }
        }
    }
    
    // Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        int v = 0;  // Potential mother vertex
        
        // First DFS to find the potential mother vertex
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                DFS(i, adj, visited);
                v = i;  // Last finished vertex might be mother vertex
            }
        }
        
        // Reset the visited array for the second DFS
        fill(visited.begin(), visited.end(), false);
        
        // Second DFS starting from potential mother vertex v
        DFS(v, adj, visited);
        for(int i = 0; i < V; i++) {
            // If there's any vertex not visited by second DFS, then v isn't a mother vertex
            if(!visited[i]) return -1;
        }
        
        return v;
    }

};

// Sample usage
int main() {
    Solution solution;
    int V = 4;  // Number of vertices
    vector<int> adj[V];
    
    // Sample directed edges
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(0);
    
    cout << "Mother Vertex is: " << solution.findMotherVertex(V, adj) << endl;
    return 0;
}
