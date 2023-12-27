#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph
{
    unordered_map<int, string> color; // For storing the status of being visited or not
    unordered_map<int, int> pd;       // for storing predecessor of the vertex
    unordered_map<int, vector<int>> adj;
    queue<int> sortedVertices;
    int count = 0;
    bool isCycle = false;

public:
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        if (u != v)
            adj[v].push_back(u);
    }
    void BFS(int s)
    {
        for (auto ver : adj)
        {
            color[ver.first] = "white";
            pd[ver.first] = 0;
        }
        color[s] = "gray";
        pd[s] = 0;
        sortedVertices.push(s);

        while (!sortedVertices.empty())
        {
            int u = sortedVertices.front();
            sortedVertices.pop();
            for (auto elem : adj[u])
            {
                if (color[elem] == "white")
                {
                    color[elem] = "gray";
                    pd[elem] = u;
                    sortedVertices.push(elem);
                }else if(color[elem] == "gray")
                    isCycle = true;
            }
            cout << u << " ->> ";
            count++;
            color[u] = "black";
        }
    }

    void DFS()
    {
        for (auto ver : adj)
        {
            color[ver.first] = "white";
            pd[ver.first] = 0;
        }

        for (auto ver : adj)
        {
            int u = ver.first;
            if (color[u] == "white")
                DFSVisit(u);
        }
    }
    void DFSVisit(int u)
    {
        color[u] = "gray";
        for (auto elem : adj[u])
        {
            if (color[elem] == "white")
            {
                pd[elem] = u;
                DFSVisit(elem);
            }
        }
        color[u] = "black";
        cout << u << " ->> ";
    }
    bool isConnected()
    {
        if (count == adj.size())
            return true;
        else
            return false;
    }
    void display(unordered_map<int, vector<int>> adj)
    {
        for (auto main : adj)
        {
            cout << "\n Vertex " << main.first << ":";
            for (int adjV : main.second)
            {
                cout << "-> " << adjV;
            }
            cout << endl;
        }
    }
};

int main()
{
    int s;
    Graph g;
    int v1, v2;
    int source;
    cout << "Enter size of the graph: ";
    cin >> s;

    for (int i = 0; i < s; i++)
    {
        cout << "For "
             << " edge " << i + 1 << endl;
        cout << "Enter first vertex: ";
        cin >> v1;
        cout << "Enter second vertex: ";
        cin >> v2;
        g.addEdge(v1, v2);
        cout << endl;
    }
    // g.addEdge(adj, 1, 2);
    // g.addEdge(adj, 2, 3);
    // g.addEdge(adj, 3, 4);
    // g.addEdge(adj, 4, 1);
    cout << "Enter source vertex: ";
    cin >> source;
    cout << "Sequence using BFS traversal: " << endl;
    g.BFS(source);
    cout << "\nSequence using DFS traversal: " << endl;
    g.DFS();

    if (g.isConnected())
        cout << "\nGraph is connected" << endl;
    else
        cout << "\nGraph is not connected" << endl;
    // g.display(adj);
    return 0;
}