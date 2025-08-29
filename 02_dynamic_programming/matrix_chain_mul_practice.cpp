#include <bits/stdc++.h>
using namespace std;
int memo[1000][1000];

int matrixChainMemo(int arr[], int i, int j)
{
    if (i == j)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];

    // try all possible ways
    int minAns = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = matrixChainMemo(arr, i, k) + matrixChainMemo(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        minAns = min(minAns, cost);
    }
    return memo[i][j] = minAns;
}

int main()
{
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    // memoization
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            memo[i][j] = -1;
        }
    }

    int minAns = matrixChainMemo(arr, 1, n - 1);
    cout<<"Min cost: "<<minAns<<endl;
    return 0;
}