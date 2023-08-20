#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>

using namespace std;

class Graph
{
private:
    unordered_map<int, list<int>> AdjacencyList;

public:
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

    void BreadthFirst(int source)
    {
        queue<int> Q;
        unordered_map<int, bool> visited;

        Q.push(source);
        visited[source] = true;

        while (!Q.empty())
        {
            int node = Q.front();
            Q.pop();

            cout << node << " ";

            for (int i : AdjacencyList[node])
            {
                if (!visited[i])
                {
                    Q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void ShowAdjacencyList()
    {
        for (auto iterator : AdjacencyList)
        {
            cout << iterator.first << " : ";
            for (int i : iterator.second)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    // Adding edges for a directed graph
    g.AddEdge(1, 2, true);
    g.AddEdge(1, 3, true);
    g.AddEdge(2, 3, true);
    g.AddEdge(2, 4, true);
    g.AddEdge(3, 4, true);
    g.AddEdge(4, 1, true);

    cout << "Adjacency List for Directed Graph:\n";
    g.ShowAdjacencyList();

    cout << "\nBreadth First Traversal starting from node 1:\n";
    g.BreadthFirst(1);

    // Clear the graph for the next example
    g = Graph();

    // Adding edges for an undirected graph
    g.AddEdge(1, 2, false);
    g.AddEdge(1, 3, false);
    g.AddEdge(2, 3, false);
    g.AddEdge(2, 4, false);
    g.AddEdge(3, 4, false);

    cout << "\n\nAdjacency List for Undirected Graph:\n";
    g.ShowAdjacencyList();

    cout << "\nBreadth First Traversal starting from node 1:\n";
    g.BreadthFirst(1);

    return 0;
}
