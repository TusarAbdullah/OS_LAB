
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

    //  Move Right First (head to end)
    for(int i = idx; i < n; i++) {
        total += abs(v[i] - head);
        head = v[i];
        cout << " -> " << head;
    }

    // Go to end (assume max track = 199)
    if(head != 199) {
        total += abs(199 - head);
        head = 199;
        cout << " -> " << head;
    }

    // Jump to start (0)
    total += 199;  // jump from 199 -> 0
    head = 0;
    cout << " -> " << head;

    // Serve remaining requests (from start to idx-1)
    for(int i = 0; i < idx; i++) {
        total += abs(v[i] - head);
        head = v[i];
        cout << " -> " << head;
    }

    cout << "\nTotal Head Movement: " << total;
}
