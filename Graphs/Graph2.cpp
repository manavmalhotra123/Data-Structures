// Adjacency List Implementation


#include <iostream>
#include <vector>
#include <list>

using namespace std;

void Show(const vector<list<int>>& adjList)
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << "Node " << i << " -> ";
        for (const int& neighbor : adjList[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

void DirectedGraph()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<list<int>> adjList(n);

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int start, end;
        cout << "Enter the start node: ";
        cin >> start;
        cout << "Enter the end node: ";
        cin >> end;
        adjList[start].push_back(end);
    }

    cout << "Adjacency list: " << endl;
    Show(adjList);
}

void UnDirectedGraph()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<list<int>> adjList(n);

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (int i = 0; i < e; i++)
    {
        int start, end;
        cout << "Enter the start node: ";
        cin >> start;
        cout << "Enter the end node: ";
        cin >> end;
        adjList[start].push_back(end);
        adjList[end].push_back(start);  // For undirected graph, add edge in both directions
    }
    
    cout << "Adjacency list: " << endl;
    Show(adjList);
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
