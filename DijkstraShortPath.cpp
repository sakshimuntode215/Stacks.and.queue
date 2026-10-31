#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int n, m;

    cout << "Enter number of cities (0 to n-1) and number of roads: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    cout << "Enter each road as: city1 city2 distance\n";

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src, dest;

    cout << "Enter source and destination city: ";
    cin >> src >> dest;

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if (d > dist[u])
            continue;

        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;

                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dest] == INT_MAX)
    {
        cout << "No route found!\n";
        return 0;
    }

    vector<int> path;

    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Shortest distance: " << dist[dest] << "\n";

    cout << "Route: ";

    for (size_t i = 0; i < path.size(); i++)
    {
        cout << path[i];

        if (i + 1 < path.size())
            cout << " -> ";
    }

    cout << "\n";

    return 0;
}

/*Enter number of cities (0 to n-1) and number of roads: 6 8

Enter each road as: city1 city2 distance

0 1 3
0 2 5
1 2 2
1 3 4
2 3 3
2 4 6
3 5 2
4 5 4

Enter source and destination city: 0 5

Shortest distance: 9
Route: 0 -> 1 -> 3 -> 5
*/
