#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int l, int mid, int r)
{

    vector<int> left(arr.begin() + l, arr.begin() + mid + 1);      // copying left part of the array with mid
    vector<int> right(arr.begin() + mid + 1, arr.begin() + r + 1); // coping right part of the array starting from mid+1

    int i = 0, j = 0, k = l; // k is l = left index
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // add the remaining array
    while (i < left.size())
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < right.size())
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);

    // finally merge
    merge(arr, l, mid, r);
}

int main()
{
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    mergeSort(arr, 0, arr.size()-1);

    // print the sorted array
    for (int x : arr)
        cout << x << " ";

    return 0;
}

// Merge Sort(Divide & Conquer)

// Idea:
// Split the array into halves until single elements remain, then merge them in sorted order.

// Process:
// Divide array into halves recursively.
// Merge sorted halves.

// Complexity:
// Always O(n log n)
// Space: O(n) (extra array needed)