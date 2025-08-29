#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int adjMat[N][N];

int main()
{
    // put it to global
    const int N = 1e3 + 5;
    int adjMat[N][N];
    // take node and edege input
    int n, m;
    cin >> n >> m;
    // taking edges input
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        // undirected graph
        adjMat[v1][v2] = 1;
        adjMat[v2][v1] = 1;
    }

    return 0;
}
