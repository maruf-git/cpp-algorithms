#include <bits/stdc++.h>
using namespace std;
int memo[100][100];

int matrixChainMemo(int arr[], int i, int j)
{
    if (i == j)
        return 0; // only one matrix, no multiplication needed
    if (memo[i][j] != -1)
        return memo[i][j];

    int minCost = INT_MAX;

    // Try all possible places to split
    for (int k = i; k < j; k++)
    {
        int cost = matrixChainMemo(arr, i, k) + matrixChainMemo(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        minCost=min(minCost,cost);
    }
    return memo[i][j]=minCost;
}

int main()
{

    int arr[] = {10, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            memo[i][j] = -1;
        }
    }
    cout << "Minimum cost(Memoization):" << matrixChainMemo(arr, 1, n - 1);

    return 0;
}