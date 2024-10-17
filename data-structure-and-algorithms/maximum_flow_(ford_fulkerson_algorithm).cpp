
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX = 100;
int n, m, s, t;
int graph[MAX][MAX];
int parent[MAX];

bool bfs()
{
    bool visited[MAX] = {false};
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                if (v == t)
                    return true;
            }
        }
    }
    return false;
}

int maxflow()
{
    int flow = 0;
    while (bfs())
    {
        int path_flow = numeric_limits<int>::max();
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, graph[u][v]);
        }
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }
        flow += path_flow;
    }
    return flow;
}

int main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u][v] = c;
    }
    cout << maxflow() << endl;
    return 0;
}
