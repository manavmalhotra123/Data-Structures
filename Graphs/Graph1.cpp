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

/*
Graph - Node Data and the Edges Data Structure
it is a kind of complex data structure -- google Maps


Examples
Node Data : a , b , c , d , e
Edge : a to b , d to e , e to b, d to b , b to c


Graphs types : 1. Directed Graph(pointed edge)  2. Undirected Graph
*/

/*
Directed Graph
a --> b
|     |
c --> d

magnitude on the edge is it's weight

the directed graph in which the weight is given on the edge is known as weighted directed graph
*/

/*
undirected graph
- with no weights is known as undirected graph
- if weight is not given then just assume them as 1
*/

/*
degree of the graph -- kite edges connected hai

in case of directed graph
outdegree -- kitne edges bhaar jaare hai
indegree -- kite edges andr aari hai edge ke
path -- sequence of the nodes

cyclic graph
acyclic graph
*/

/*
graph implementation
1. adjacency list
2. adjacency matrix
*/

// Adjacency Matrix
/*
0 -- 1
|  / |
2    3

1. count number of nodes
n = 4
2. make the matrix of 4 X 4

Edges

     0 1 2 3

0    0 0 0 0
1    0 0 0 0
2    0 0 0 0
3    0 0 0 0

3. filling the matrix
     0 1 2 3

0    0 1 1 0
1    1 0 1 1
2    1 1 0 0
3    0 1 0 0

This Matrix is known as the adjacency matrix
*/
using namespace std;

void Show(vector<vector<int>> input)
{
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i].size(); j++)
        {
            cout << input[i][j] << " ";
        }
        cout << endl;
    }
}

void DirectedGraph()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Empty Adjacency matrix.." << endl;
    vector<vector<int>> Matrix(n, vector<int>(n, 0));
    Show(Matrix);

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int start;
        int end;
        cout << "Enter the start node: ";
        cin >> start;
        cout << "Enter the end node: ";
        cin >> end;
        Matrix[start][end] = 1;
    }

    cout << "Adjacency matrix: " <<endl;
    Show(Matrix);
}

void UnDirectedGraph()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Empty Adjacency matrix.." << endl;
    vector<vector<int>> Matrix(n, vector<int>(n, 0));
    Show(Matrix);

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int start;
        int end;
        cout << "Enter the start node: ";
        cin >> start;
        cout << "Enter the end node: ";
        cin >> end;
        Matrix[start][end] = 1;
        Matrix[end][start] = 1;  // For undirected graph, update both directions
    }
    
    cout << "Adjacency matrix: " << endl;
    Show(Matrix);
}



void WeightedDirectedGraph()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Empty Adjacency matrix.." << endl;
    vector<vector<int>> Matrix(n, vector<int>(n, 0));
    Show(Matrix);

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int start;
        int end;
        int weight;
        cout << "Enter the start node: ";
        cin >> start;
        cout << "Enter the end node: ";
        cin >> end;
        cout << "Enter the weight: ";
        cin >> weight;
        Matrix[start][end] = weight;
    }

    cout << "Adjacency matrix: " <<endl;
    Show(Matrix);
}


int main(int argc, char const *argv[])
{
    char choice;
    cout << "Enter U for undirected graph and D for directed graph.." << endl;
    cin >> choice;

    if (choice == 'U')
    {
        UnDirectedGraph();
    }
    else if (choice == 'D')
    {
        DirectedGraph();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}