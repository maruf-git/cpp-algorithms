#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];
bool visited[N];

void dfs(int source)
{
    if (visited[source])
        return;
    visited[source] = true;
    // what process
    cout << source << " "; // output graph traversal
    for (auto node : graph[source])
    {
        // what process
        dfs(node);
        // what process
    }
    // what process
}

int main()
{

    int n, m; // nodes , edges
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        // undirected graph
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    memset(visited, false, sizeof(visited));
    dfs(0);
    return 0;
}