#include <bits/stdc++.h>
using namespace std;

bool compareByEnd(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second; // sort by finish time
}

int main()
{
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    vector<pair<int, int>> vp; // {start, end}

    cout << "Enter start times: ";
    vector<int> start(n);
    for (int i = 0; i < n; i++) cin >> start[i];

    cout << "Enter finish times: ";
    vector<int> finish(n);
    for (int i = 0; i < n; i++) cin >> finish[i];

    // Store as {start, end}
    for (int i = 0; i < n; i++)
        vp.push_back({start[i], finish[i]});

    // Sort by end time
    sort(vp.begin(), vp.end(), compareByEnd);

    cout << "\nSelected activities (start, finish):\n";
    int lastFinish = -1;

    // Greedy selection
    for (auto act : vp)
    {
        int s = act.first;
        int f = act.second;
        if (s >= lastFinish)
        {
            cout << "(" << s << ", " << f << ")\n";
            lastFinish = f;
        }
    }

    return 0;
}
