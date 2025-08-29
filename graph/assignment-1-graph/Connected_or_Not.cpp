#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e3 + 5;
int graph[N][N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        graph[i][i] = 1;
    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1][n2] = 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        if (graph[n1][n2])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}