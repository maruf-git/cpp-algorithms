#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e3 + 5;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    // sort(graph.begin(), graph.end(), greater<int>());
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        if (graph[n].size() == 0)
            cout << -1;
        else
        {
            sort(graph[n].begin(), graph[n].end(), greater<int>());
            for (auto u : graph[n])
            {
                cout << u << " ";
            }
        }
        cout << endl;
    }

    return 0;
}