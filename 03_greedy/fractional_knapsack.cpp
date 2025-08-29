#include <bits/stdc++.h>
using namespace std;

const int N = 100; // max number of items
double ratioArr[N];
int idxArr[N];

bool cmpFunc(int a, int b) {
    return ratioArr[a] > ratioArr[b]; // higher ratio first
}

double fractionalKnapsack(int capacity, int wt[], int val[], int n) {
    // Calculate value-to-weight ratio and store indices
    for (int i = 0; i < n; i++) {
        ratioArr[i] = (double)val[i] / wt[i];
        idxArr[i] = i;
    }

    // Sort indices by ratio (descending order)
    sort(idxArr, idxArr + n, cmpFunc);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        int item = idxArr[i];
        if (capacity >= wt[item]) {
            // Take full item
            capacity -= wt[item];
            totalValue += val[item];
        } else {
            // Take fraction of item
            totalValue += val[item] * ((double)capacity / wt[item]);
            break; // bag is full
        }
    }
    return totalValue;
}

int main() {
    int n = 3; // number of items
    int capacity = 50;
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};

    double maxValue = fractionalKnapsack(capacity, wt, val, n);

    cout << "Maximum value in Knapsack = " << maxValue << endl;
    return 0;
}
