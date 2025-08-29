#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
bool visited[N];
vector<int> graph[N];
bool hasCycle = false;
void dfs(int source, int parent)
{
    if (visited[source])
        return;
    visited[source] = true;
    cout << source << " ";
    for (auto child : graph[source])
    {
        if (visited[child] && child != parent)
        {
            hasCycle = true;
        }
        dfs(child, source);
    }
}

int main()
{

    int n, m; // nodes, edges
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    int parent = -1;
    dfs(1, parent);
    cout << endl;
    if (hasCycle)
        cout << "The graph has cycle" << endl;
    else
        cout << "The graph does not has cycle" << endl;

    return 0;
}