#include <bits/stdc++.h>
using namespace std;
int memo[1000][1000];
int lcsMemo(string a, string b, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];

    // if matched
    if (a[i] == b[j])
        return memo[i][j] = 1 + lcsMemo(a, b, i - 1, j - 1);
    else
        return memo[i][j] = max(lcsMemo(a, b, i - 1, j), lcsMemo(a, b, i, j - 1));
}

int main()
{

    string a = "abcde";
    string b = "ace";
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            memo[i][j] = -1;
        }
    }
    int ans = lcsMemo(a, b, a.size() - 1, b.size() - 1);
    cout << "Length: " << ans << endl;

    return 0;
}