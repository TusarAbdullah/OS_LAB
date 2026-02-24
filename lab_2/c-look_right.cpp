
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, head;
    cout << "Enter number of path: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the paths: ";
    for(int i = 0; i < n; i++)
        cin >> v[i];

    cout << "Enter initial head position: ";
    cin >> head;

    int total = 0;

    sort(v.begin(), v.end());  // sort requests

    cout << "\nqueue: " << head;

    int idx = lower_bound(v.begin(), v.end(), head) - v.begin();

    //  Move Right First (head to last request)
    for(int i = idx; i < n; i++) {
        total += abs(v[i] - head);
        head = v[i];
        cout << " -> " << head;
    }

    // Jump to first request on left side
    for(int i = 0; i < idx; i++) {
        total += abs(v[i] - head);
        head = v[i];
        cout << " -> " << head;
    }

    cout << "\nTotal Head Movement: " << total;
}
//98 183 37 122 14 124 65 67
