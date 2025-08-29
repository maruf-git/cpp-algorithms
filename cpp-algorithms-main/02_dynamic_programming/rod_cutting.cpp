#include <bits/stdc++.h>
using namespace std;

// memoization approach(top-down)
int memo[1000000];
int rodCuttingMemo(int price[], int len)
{
    // base condition: no rod left
    if (len == 0)
        return 0;

    // if already computed , return
    if (memo[len] != -1)
        return memo[len];

    int mxProfit = INT_MIN;

    // try cutting rod in every possible length (1 to n)
    for (int cutLen = 1; cutLen <= len; cutLen++)
    {
        int profit = price[cutLen - 1] + rodCuttingMemo(price, len - cutLen);
        mxProfit = max(mxProfit, profit);
    }

    // save and return result
    return memo[len] = mxProfit;
}

// bottom-up approach(tabulation)
int rodCuttingTabulation(int price[], int len)
{
    int dp[len + 1];
    dp[0] = 0;

    // build the table iteratively
    for (int rodLen = 1; rodLen <= len; rodLen++)
    {
        int mxProfit = INT_MIN;
        for (int cutLen = 1; cutLen <= rodLen; cutLen++)
        {
            mxProfit = max(mxProfit, price[cutLen - 1] + dp[rodLen - cutLen]);
        }
        dp[rodLen] = mxProfit;
    }
    return dp[len];
}

int main()
{

    int n;
    cout << "Enter Rod Length: ";
    cin >> n;

    int price[n];
    // input the rod price for i+1
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++)
        cin >> price[i];

    // initialize the memoization array
    for (int i = 0; i < 1000000; i++)
        memo[i] = -1;

    cout << "Max Profit(Memoization): " << rodCuttingMemo(price, n) << endl;      // passing price array and length of the rod
    cout << "Max Profit(tabulation): " << rodCuttingTabulation(price, n) << endl; // passing price array and length of the rod
    return 0;
}