#include <bits/stdc++.h>
using namespace std;

int memo[1000][1000];

int knapsackMemo(int wt[], int val[], int W, int idx)
{
    // if index is 0 or left weight in the bag less than equal 0
    if (idx < 0 || W <= 0)
        return 0;

    if (memo[idx][W] != -1)
        return memo[idx][W];
    // dont choose item at idx
    int ans = knapsackMemo(wt, val, W, idx - 1);
    // choose item idx
    if (W - wt[idx] >= 0)
        ans = max(ans, knapsackMemo(wt, val, W - wt[idx], idx - 1) + val[idx]);
    return memo[idx][W] = ans;
}

int knapsackTab(int wt[], int val[], int W, int n)
{
    int dp[n][W + 1]; // dp[i][w] = max value using items 0..i with capacity w

    // Step 1: Fill first row (only first item is considered)
    for (int w = 0; w <= W; w++)
    {
        if (wt[0] <= w)
            dp[0][w] = val[0]; // can take it
        else
            dp[0][w] = 0; // can't take it
    }

    // Step 2: Fill the rest of the table
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTake = dp[i - 1][w]; // don't take current item
            int take = 0;
            if (wt[i] <= w)
                take = val[i] + dp[i - 1][w - wt[i]]; // take current item
            dp[i][w] = max(take, notTake);            // best choice
        }
    }

    return dp[n - 1][W]; // answer is in last cell
}

int main()
{

    int wt[] = {1, 3, 4, 5};  // weight of each items
    int val[] = {1, 4, 5, 7}; // price of each items

    int W = 7; // total weight capacity of the knapsack
    int n = 4; // n = count of items

    // initializing memo array
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            memo[i][j] = -1;
        }
    }

    cout << "Maximum Value(Memoization): " << knapsackMemo(wt, val, W, n - 1) << endl;
    cout << "Maximum Value(Tabulation): " << knapsackTab(wt, val, W, n) << endl;

    return 0;
}