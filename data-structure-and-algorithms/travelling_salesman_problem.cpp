
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> path;
int minCost = numeric_limits<int>::max();

void solve(int curr, int count, int cost, vector<bool> &visited)
{
    if (count == n && graph[curr][0])
    {
        minCost = min(minCost, cost + graph[curr][0]);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[curr][i])
        {
            visited[i] = true;
            solve(i, count + 1, cost + graph[curr][i], visited);
            visited[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    graph.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    vector<bool> visited(n, false);
    visited[0] = true;
    solve(0, 1, 0, visited);

    cout << minCost << endl;

    return 0;
}
