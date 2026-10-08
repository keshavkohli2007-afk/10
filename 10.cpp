#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstra(int V, vector<vector<pair<int, int>>> &adj, int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        if (u == -1 || dist[u] == INT_MAX)
            break;

        visited[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    cout << "Vertex\tDistance from Source\n";

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << "\tINF\n";
        else
            cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter source destination weight:\n";

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(V, adj, src);

    return 0;
}