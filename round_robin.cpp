#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    string process[n];
    int burst[n];
    int rem_burst[n];

    cout << "Enter process name and burst time:\n";
    for(int i = 0; i < n; i++) {
        cin >> process[i] >> burst[i];
        rem_burst[i] = burst[i];
    }

    int time_quantum;
    cout << "Enter time quantum: ";
    cin >> time_quantum;

    int time = 0;
    bool done = false;

    cout << "\nGantt Chart:\n";

    while (!done) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rem_burst[i] > 0) {
                done = false;

                int slice = min(rem_burst[i], time_quantum);

                cout << time << " " << process[i] << " ";
                time += slice;
                cout << time << " ";

                rem_burst[i] -= slice;
            }
        }
    }

    // Calculate waiting time
    int finish[n], waiting[n];
    int temp_rem[n];
    copy(burst, burst+n, temp_rem);
    fill(finish, finish+n, 0);

    int temp_time = 0;
    done = false;
    while (!done) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (temp_rem[i] > 0) {
                done = false;
                int slice = min(temp_rem[i], time_quantum);
                temp_rem[i] -= slice;
                temp_time += slice;
                if (temp_rem[i] == 0)
                    finish[i] = temp_time;
            }
        }
    }


    float total_wait = 0;
    for(int i = 0; i < n; i++) {
        waiting[i] = finish[i] - burst[i];
        total_wait += waiting[i];
    }

    float avg_wait = total_wait / n;
    cout << "\n\nAverage Waiting Time: " << avg_wait << endl;

    return 0;
}
