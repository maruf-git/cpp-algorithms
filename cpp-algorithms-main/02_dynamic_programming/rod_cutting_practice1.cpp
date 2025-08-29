#include <bits/stdc++.h>
using namespace std;
int memo[1000000];
int rodCuttingMemo(int price[], int len)
{
    if (len <= 0)
        return 0;
    if (memo[len] != -1)
        return memo[len];
        
    int maxProfit = INT_MIN;

    for (int cut = 1; cut <= len; cut++)
    {
        int profit = price[cut - 1] + rodCuttingMemo(price, len - cut);
        maxProfit = max(maxProfit, profit);
    }
    return memo[len] = maxProfit;
}

int main()
{

    int n; // length of the rod
    int price[] = {5, 10, 15, 3, 18, 3, 1};
    n = 7;
    for (int i = 0; i < 1000000; i++)
        memo[i] = -1;
    int maxProfit = rodCuttingMemo(price, 7);

    cout << "Max Profit: " << maxProfit << endl;

    return 0;
}