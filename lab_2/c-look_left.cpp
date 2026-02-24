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

    //  Move Left First (head to smallest request)
    for(int i = idx - 1; i >= 0; i--) {
        total += abs(v[i] - head);
        head = v[i];
        cout << " -> " << head;
    }

    // Jump to last request on right side
    for(int i = n - 1; i >= idx; i--) {
        total += abs(v[i] - head);
        head = v[i];
        cout << " -> " << head;
    }

    cout << "\nTotal Head Movement: " << total;
}
