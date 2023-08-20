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
    // unordered_map is used here : insertion time : O(1)
    unordered_map<int, list<int>> AdjacencyList;

public:
    void AddEdge(int start, int end, bool direction)
    {
        // if direction is false then undirected
        // if direction is true then directed edge

        // start mai end ko insert kr diya chahe directed hai ya indirected
        AdjacencyList[start].push_back(end);

        // if undirected then end to start bhi add krna hoga
        if (direction == false)
        {
            AdjacencyList[end].push_back(start);
        }
    }

    void ShowAdjacencyList()
    {
        for (auto iterator : AdjacencyList)
        {
            cout << iterator.first << " : ";
            for (auto i : iterator.second)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
};

class WeightedGraph
{
private:
    // using unordered_map to store the graph
    unordered_map<int, list<pair<int, int>>> AdjacencyList;

public:
    // add edge function
    void AddEdge(int start, int end, int weight, bool direction)
    {
        AdjacencyList[start].push_back({end, weight});
        // if directed
        if (direction == false)
        {
            AdjacencyList[end].push_back({start, weight});
        }
    }

    void ShowAdjacencyList()
    {
        for (auto iterator : AdjacencyList)
        {
            cout << iterator.first << " : ";
            for (auto i : iterator.second)
            {
                cout << "(" << i.first << "," << i.second << "),";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph directedGraph;

    directedGraph.AddEdge(0, 1, true);
    directedGraph.AddEdge(0, 2, true);
    directedGraph.AddEdge(1, 2, true);
    directedGraph.AddEdge(2, 0, true);
    directedGraph.AddEdge(2, 3, true);
    directedGraph.AddEdge(3, 3, true);

    cout << "Directed Graph:" << endl;
    directedGraph.ShowAdjacencyList();
    cout << endl;

    Graph undirectedGraph;

    undirectedGraph.AddEdge(0, 1, false);
    undirectedGraph.AddEdge(0, 2, false);
    undirectedGraph.AddEdge(1, 2, false);
    undirectedGraph.AddEdge(2, 0, false);
    undirectedGraph.AddEdge(2, 3, false);
    undirectedGraph.AddEdge(3, 3, false);

    cout << "Undirected Graph:" << endl;
    undirectedGraph.ShowAdjacencyList();
    cout << endl;

    WeightedGraph weightedDirectedGraph;

    weightedDirectedGraph.AddEdge(0, 1, 5, true);
    weightedDirectedGraph.AddEdge(0, 2, 3, true);
    weightedDirectedGraph.AddEdge(1, 2, 2, true);
    weightedDirectedGraph.AddEdge(2, 0, 8, true);
    weightedDirectedGraph.AddEdge(2, 3, 7, true);
    weightedDirectedGraph.AddEdge(3, 3, 6, true);

    cout << "Weighted Directed Graph:" << endl;
    weightedDirectedGraph.ShowAdjacencyList();
    cout << endl;

    WeightedGraph weightedUndirectedGraph;

    weightedUndirectedGraph.AddEdge(0, 1, 5, false);
    weightedUndirectedGraph.AddEdge(0, 2, 3, false);
    weightedUndirectedGraph.AddEdge(1, 2, 2, false);
    weightedUndirectedGraph.AddEdge(2, 0, 8, false);
    weightedUndirectedGraph.AddEdge(2, 3, 7, false);
    weightedUndirectedGraph.AddEdge(3, 3, 6, false);

    cout << "Weighted Undirected Graph:" << endl;
    weightedUndirectedGraph.ShowAdjacencyList();

    return 0;
}
