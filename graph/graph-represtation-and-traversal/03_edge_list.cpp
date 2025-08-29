#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<pair<int, int>> edge_list;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2; 
        edge_list.push_back({v1, v2});
    }

    return 0;
}