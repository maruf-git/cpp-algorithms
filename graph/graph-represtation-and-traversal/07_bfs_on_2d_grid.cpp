#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char arr[N][N];
bool visited[N][N];
int level[N][N];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        cout << par_i << " " << par_j << endl;
        for (int i = 0; i < 4; i++)
        {
            int ci, cj;
            ci = par_i + moves[i].first;
            cj = par_j + moves[i].second;

            if (isValid(ci, cj, n, m)) // checking if valid move or not
            {
                if (!visited[ci][cj] && arr[ci][cj]=='.')
                {
                    q.push({ci, cj});
                    visited[ci][cj] = true;
                    level[ci][cj] = level[par_i][par_j] + 1;
                }
            }
        }
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
    memset(level, -1, sizeof(level));
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    bfs(si, sj, n, m);
    cout << "Distance: " << level[di][dj];
    return 0;
}