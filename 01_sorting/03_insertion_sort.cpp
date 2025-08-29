#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    insertionSort(arr);

    // print the sorted array
    for (int x : arr)
        cout << x << " ";

    return 0;
}

// Insertion Sort 🃏 (The Card Player’s Trick)

// Idea:
// Like sorting cards in your hand — you pick a card and insert it into the correct 
// position among the already sorted ones.

// Process:
// Start from the second element.
// Move it left until it’s in the correct position.
// Repeat for all elements.

// Complexity:
// Best: O(n) (already sorted)
// Worst: O(n²)
// Space: O(1)