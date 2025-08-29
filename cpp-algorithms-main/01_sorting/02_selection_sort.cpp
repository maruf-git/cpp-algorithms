#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    int minIdx = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIdx])
        minIdx = j;
    }
    swap(arr[i], arr[minIdx]);
  }
}

int main()
{
  vector<int> arr = {5, 2, 9, 1, 5, 6};
  selectionSort(arr); 

  // print the sorted array
  for (int x : arr)
    cout << x << " ";

  return 0;
}

// Selection Sort 🎯 (The Organised Way)

// Idea:
// Like picking the smallest card in a hand and putting it in its correct place one by one.

// Process:
// Find the smallest element.
// Swap it with the first position.
// Move to the next position and repeat.

// Complexity:
// Always O(n²)
// Space: O(1)