#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
vector<int> graph[N];
bool visited[N];

void bfs(int src) // source/start node for traversal
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // print traversal
        cout << frontNode << " ";

        for (auto neighbor : graph[frontNode])
        {
            // check if already visited then continue
            if (visited[neighbor])
                continue;
            // if not visited then push to the queue
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }
}

int main()
{

    // input node and edge
    int n, m;
    cin >> n >> m;
    // input edges
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        // unidrected graph
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    return 0;
}