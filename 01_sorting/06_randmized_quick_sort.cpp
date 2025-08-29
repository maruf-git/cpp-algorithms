#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {

    // Randomized pivot
    int randomPivot = low + rand() % (high - low + 1);
    swap(arr[randomPivot], arr[high]);

    // normal partition for quick sort
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    srand(time(0)); // seed for randomness
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) cout << x << " ";
    return 0;
}

// Quick Sort ⚡ (The Speed Demon)

// Idea:
// Pick a (random) pivot element, place it in correct position, put smaller elements to its left, bigger to its right.

// Process:
// Choose a random pivot.
// Partition array into two parts.
// Recursively sort both parts.

// Complexity:
// Best/Average: O(n log n)
// Worst: O(n²) (bad pivot choice)
// Space: O(log n) (stack space)
