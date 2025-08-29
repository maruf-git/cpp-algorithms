#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break; // already sorted
    }
}

int main()
{

    vector<int> arr = {5, 2, 9, 1, 5, 6}; // test array
    bubbleSort(arr);                      // called bubble sort on the array

    // print the sorted array
    for (auto u : arr)
        cout << u << " ";

    return 0;
}

// Bubble Sort 🫧 (The Lazy Way)

// Idea:
// Imagine you have a row of books with random heights.
// You keep swapping adjacent books if the left one is
// taller than the right, until no swaps are needed.

// Process:
// Compare each pair of adjacent elements.
// Swap if they are in the wrong order.
// Repeat until no swaps occur.

// Complexity:
// Best Case: O(n) (already sorted)
// Worst Case: O(n²)
// Space: O(1)