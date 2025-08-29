#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char arr[N][N];
bool visited[N][N];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void dfs(int si, int sj, int n, int m)
{
    if (visited[si][sj])
        return;
    visited[si][sj] = true;
    cout << si << " " << sj << endl;
    for (int i = 0; i < 4; i++)
    {
        int ci, cj;
        ci = si + moves[i].first;
        cj = sj + moves[i].second;
        if (isValid(ci, cj, n, m)) // checking if valid move or not
            dfs(ci, cj, n, m);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    memset(visited, false, sizeof(visited));
    int si, sj;
    cin >> si >> sj;
    dfs(si, sj, n, m);

    return 0;
}