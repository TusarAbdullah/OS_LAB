#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of path : ";
    cin >> n;

    int arr[n];

    cout << "Enter the paths : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int head;
    cout << "Enter initial head position: ";
    cin >> head;

    int total_movement = 0;

    cout << "\n\nQueue: " << head;

    for(int i = 0; i < n; i++) {
        total_movement += abs(arr[i] - head);
        head = arr[i];
        cout << " -> " << head;
    }

    cout << "\n\nTotal Head Movement: " << total_movement << endl;


    return 0;
}

