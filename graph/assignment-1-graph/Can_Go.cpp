#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1e3 + 5;
int n, m;
bool visited[N][N];
char grid[N][N];
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void dfs(int si, int sj)
{
    if (visited[si][sj])
        return;
    visited[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + moves[i].first;
        int cj = sj + moves[i].second;
        if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        {
            if (grid[ci][cj] != '#')
            {
                dfs(ci, cj);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    dfs(si, sj);
    if (visited[di][dj])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}