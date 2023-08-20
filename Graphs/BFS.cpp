// BFS is like level order traversal
// is every tree a graph -- yes
// is every graph a tree -- no

/*
Breadth First Search
*/

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

        if (direction == false)
        {
            // if bi-directed then reverse insertion
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

int main()
{

    return 0;
}