
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
    int max_track = 199;   // maximum track
    int min_track = 0;     // minimum track

    sort(v.begin(), v.end());  // sort requests

    cout << "\nqueue: " << head;

    int idx = lower_bound(v.begin(), v.end(), head) - v.begin();

    //  Move Left First (serve requests < head)
    for(int i = idx - 1; i >= 0; i--) {
        total += abs(v[i] - head);
        head = v[i];
        cout << " -> " << head;
    }

    // Go to start (0) if not already there
    if(head != min_track) {
        total += abs(head - min_track);
        head = min_track;
        cout << " -> " << head;
    }

    // Jump to max track (circular)
    total += max_track - min_track;  // 0 -> 199
    head = max_track;
    cout << " -> " << head;

    // Serve remaining requests (right side)
    for(int i = idx; i < n; i++) {
        total += abs(v[i] - head);
        head = v[i];
        cout << " -> " << head;
    }

    cout << "\nTotal Head Movement: " << total;
}
