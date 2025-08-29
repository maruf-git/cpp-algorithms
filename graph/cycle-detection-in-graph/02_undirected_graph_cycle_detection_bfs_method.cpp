#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
bool visited[N];
int parent[N];
bool hasCycle = false;
vector<int> graph[N];

void bfs(int source)
{
    queue<int> q; // pari<node,parent>
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    int i = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto child : graph[node])
        {
            if (visited[child] && parent[node] != child)
            {
                hasCycle = true;
            }
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent[child] = node;
            }
        }
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
    memset(visited, false, sizeof(visited));
    memset(parent,-1,sizeof(parent));
    int parent = -1;
    bfs(1);
    cout << endl;
    if (hasCycle)
        cout << "The graph has cycle" << endl;
    else
        cout << "The graph does not has cycle" << endl;

    return 0;
}