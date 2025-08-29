#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
bool visited[N];
vector<int> graph[N];
bool hasCycle = false;
int color[N]; // pathvisit
// 0->not visited
// 1->currently exploring(in recursion stack)
// 2->fully explored
void dfs(int source)
{
    if (visited[source])
        return;
    visited[source] = true;
    color[source] = 1; // true
    cout << source << " ";
    for (auto child : graph[source])
    {
        if (color[child] == 1)
        {
            hasCycle = true;
        }
        dfs(child);
    }
    color[source] = 2; // false
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
    }
    int parent = -1;
    dfs(1);
    cout << endl;
    if (hasCycle)
        cout << "The graph has cycle" << endl;
    else
        cout << "The graph does not has cycle" << endl;

    return 0;
}