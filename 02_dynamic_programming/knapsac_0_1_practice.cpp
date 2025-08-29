#include <bits/stdc++.h>
using namespace std;
int memo[1000][1000]; // idx, wt
int knapsackMemo(int wts[], int val[], int leftW, int idx)
{
    if (leftW <= 0)
        return 0;
    if (idx < 0)
        return 0;

    if (memo[idx][leftW] != -1)
        return memo[idx][leftW];

    // choose not take
    int profit = knapsackMemo(wts, val, leftW, idx - 1);
    // choose take
    if (leftW >= wts[idx])
        profit = max(profit, val[idx] + knapsackMemo(wts, val, leftW - wts[idx], idx - 1));
    return memo[idx][leftW]=profit;
}

int main()
{
    int n;                        // items
    int wts[] = {10, 5, 2, 3, 1}; // wights
    int val[] = {2, 5, 9, 3, 5};  // item value
    int W = 30;                   // bag max weight
    n = 5;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            memo[i][j] = -1;
        }
    }
    int mxProfit = knapsackMemo(wts, val, W, n - 1);
    cout << "Max Profit: " << mxProfit << endl;

    return 0;
}