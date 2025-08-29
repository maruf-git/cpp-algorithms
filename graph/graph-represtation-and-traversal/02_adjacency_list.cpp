#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> graph[N];
// or vector<vector<int>>graph
int main()
{

    // put it in top
    const int N = 1e6 + 5;
    vector<int> graph[N];
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
