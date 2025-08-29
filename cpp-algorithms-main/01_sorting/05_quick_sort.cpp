#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // last element as pivot
    int i = low - 1; //We keep a pointer i that tracks where the smaller elements should end:
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]); // move smaller element forward
        }
    }
    swap(arr[i + 1], arr[high]); // put pivot in correct position
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);  // excluding pivot
        quickSort(arr, pivot + 1, high); // excluding pivot
    }
}

int main()
{

    vector<int> arr = {5, 2, 9, 1, 5, 6};
    quickSort(arr, 0, arr.size() - 1);

    // print the sorted array
    for (int x : arr)
        cout << x << " ";

    return 0;
}

// Quick Sort ⚡ (The Speed Demon)

// Idea:
// Pick a pivot element, place it in correct position, put smaller elements to its left, bigger to its right.

// Process:
// Choose a pivot.
// Partition array into two parts.
// Recursively sort both parts.

// Complexity:
// Best/Average: O(n log n)
// Worst: O(n²) (bad pivot choice)
// Space: O(log n) (stack space)