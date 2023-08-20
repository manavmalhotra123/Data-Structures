#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

class Graph
{
private:
    unordered_map<int, list<int>> AdjacencyList;
    unordered_map<int, bool> visited;

public:
    Graph()
    {
        // Initialize the visited map for all nodes
        for (auto& iterator : AdjacencyList)
        {
            visited[iterator.first] = false;
        }
    }

    void AddEdge(int start, int end, bool direction)
    {
        // adding the node to the graph list
        AdjacencyList[start].push_back(end);

        if (!direction)
        {
            // For undirected graphs, add the reverse edge as well
            AdjacencyList[end].push_back(start);
        }
    }

    const unordered_map<int, list<int>>& GetAdjacencyList() const
    {
        return AdjacencyList;
    }

    void DepthFirst(int node)
    {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : AdjacencyList[node])
        {
            if (!visited[neighbor])
            {
                DepthFirst(neighbor);
            }
        }
    }

    void DepthFirstTraversal(int source)
    {
        DepthFirst(source);
    }
};

int main()
{
    Graph g;

    // Adding edges for an undirected graph
    g.AddEdge(1, 2, false);
    g.AddEdge(1, 3, false);
    g.AddEdge(2, 3, false);
    g.AddEdge(2, 4, false);
    g.AddEdge(3, 4, false);

    cout << "Adjacency List for Undirected Graph:\n";
    for (const auto& iterator : g.GetAdjacencyList())
    {
        cout << iterator.first << " : ";
        for (int i : iterator.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << "\nDepth First Traversal starting from node 1:\n";
    g.DepthFirstTraversal(1);

    return 0;
}
