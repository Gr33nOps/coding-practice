/*
FCFS ALGO

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int pid;    // Process ID
    int at;     // Arrival Time
    int bt;     // Burst Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
};

void fcfs(vector<Process>& processes) {
    // Sort processes by arrival time
    sort(processes.begin(), processes.end(),
        [](const Process& a, const Process& b) {
            return a.at < b.at;
        });

    int current_time = 0;
    float total_wt = 0, total_tat = 0;

    for (auto& proc : processes) {
        // If current time is less than arrival time, wait until process arrives
        if (current_time < proc.at) {
            current_time = proc.at;
        }

        // Calculate completion time
        proc.ct = current_time + proc.bt;

        // Calculate turnaround time
        proc.tat = proc.ct - proc.at;

        // Calculate waiting time
        proc.wt = proc.tat - proc.bt;

        // Update current time
        current_time = proc.ct;

        // Accumulate totals
        total_wt += proc.wt;
        total_tat += proc.tat;
    }

    // Display results
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "---\t--\t--\t--\t---\t--\n";

    for (const auto& proc : processes) {
        cout << proc.pid << "\t" << proc.at << "\t" << proc.bt << "\t"
            << proc.ct << "\t" << proc.tat << "\t" << proc.wt << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_wt / processes.size() << "\n";
    cout << "Average Turnaround Time: " << total_tat / processes.size() << "\n";
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time for process " << processes[i].pid << ": ";
        cin >> processes[i].at;
        cout << "Enter burst time for process " << processes[i].pid << ": ";
        cin >> processes[i].bt;
    }

    // Execute FCFS algorithm
    fcfs(processes);

    return 0;
}
*/

/*
SJF ALGO

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int pid;    // Process ID
    int at;     // Arrival Time
    int bt;     // Burst Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
};

void sjf(vector<Process>& processes) {
    int n = processes.size();
    int current_time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;

    // Track which processes are completed
    vector<bool> is_completed(n, false);

    while (completed < n) {
        int min_bt = 9999, min_idx = -1;

        // Find process with shortest burst time among arrived processes
        for (int i = 0; i < n; i++) {
            if (!is_completed[i] && processes[i].at <= current_time && processes[i].bt < min_bt) {
                min_bt = processes[i].bt;
                min_idx = i;
            }
        }

        // If no process is ready, advance time
        if (min_idx == -1) {
            current_time++;
            continue;
        }

        // Process the selected process
        current_time += processes[min_idx].bt;
        processes[min_idx].ct = current_time;
        processes[min_idx].tat = processes[min_idx].ct - processes[min_idx].at;
        processes[min_idx].wt = processes[min_idx].tat - processes[min_idx].bt;

        total_wt += processes[min_idx].wt;
        total_tat += processes[min_idx].tat;
        is_completed[min_idx] = true;
        completed++;
    }

    // Display results
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "---\t--\t--\t--\t---\t--\n";

    for (const auto& proc : processes) {
        cout << proc.pid << "\t" << proc.at << "\t" << proc.bt << "\t"
            << proc.ct << "\t" << proc.tat << "\t" << proc.wt << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_wt / n << "\n";
    cout << "Average Turnaround Time: " << total_tat / n << "\n";
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time for process " << processes[i].pid << ": ";
        cin >> processes[i].at;
        cout << "Enter burst time for process " << processes[i].pid << ": ";
        cin >> processes[i].bt;
    }

    // Execute SJF algorithm
    sjf(processes);

    return 0;
}
*/

/*
RR- Round Robin ALGO

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct Process {
    int pid;    // Process ID
    int at;     // Arrival Time
    int bt;     // Burst Time
    int rt;     // Remaining Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
};

void roundRobin(vector<Process>& processes, int quantum) {
    int n = processes.size();
    int current_time = 0, completed = 0;
    float total_wt = 0, total_tat = 0;

    queue<int> ready_queue;
    vector<bool> in_queue(n, false);

    // Initialize remaining time
    for (int i = 0; i < n; i++) {
        processes[i].rt = processes[i].bt;
    }

    // Add initial processes to queue
    for (int i = 0; i < n; i++) {
        if (processes[i].at <= current_time) {
            ready_queue.push(i);
            in_queue[i] = true;
        }
    }

    while (completed < n) {
        if (ready_queue.empty()) {
            current_time++;
            // Check for newly arrived processes
            for (int i = 0; i < n; i++) {
                if (!in_queue[i] && processes[i].at <= current_time && processes[i].rt > 0) {
                    ready_queue.push(i);
                    in_queue[i] = true;
                }
            }
            continue;
        }

        int current_process = ready_queue.front();
        ready_queue.pop();
        in_queue[current_process] = false;

        // Execute process for quantum time or remaining time
        int exec_time = min(quantum, processes[current_process].rt);
        current_time += exec_time;
        processes[current_process].rt -= exec_time;

        // Check for newly arrived processes during execution
        for (int i = 0; i < n; i++) {
            if (!in_queue[i] && processes[i].at <= current_time &&
                processes[i].rt > 0 && i != current_process) {
                ready_queue.push(i);
                in_queue[i] = true;
            }
        }

        // If process is completed
        if (processes[current_process].rt == 0) {
            processes[current_process].ct = current_time;
            processes[current_process].tat = processes[current_process].ct - processes[current_process].at;
            processes[current_process].wt = processes[current_process].tat - processes[current_process].bt;

            total_wt += processes[current_process].wt;
            total_tat += processes[current_process].tat;
            completed++;
        }
        else {
            // Add back to queue if not completed
            ready_queue.push(current_process);
            in_queue[current_process] = true;
        }
    }

    // Display results
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "---\t--\t--\t--\t---\t--\n";

    for (const auto& proc : processes) {
        cout << proc.pid << "\t" << proc.at << "\t" << proc.bt << "\t"
            << proc.ct << "\t" << proc.tat << "\t" << proc.wt << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_wt / n << "\n";
    cout << "Average Turnaround Time: " << total_tat / n << "\n";
}

int main() {
    int n, quantum;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter time quantum: ";
    cin >> quantum;

    vector<Process> processes(n);

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time and burst time for process " << processes[i].pid << ": ";
        cin >> processes[i].at >> processes[i].bt;
    }

    // Execute Round Robin algorithm
    roundRobin(processes, quantum);

    return 0;
}
*/
/*
priority ALGO

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Process {
    int pid, at, bt, priority;
    int ct = 0, tat = 0, wt = 0;
};

void priorityScheduling(vector<Process>& processes) {
    int n = processes.size(), completed = 0, time = 0;
    float total_wt = 0, total_tat = 0;
    vector<bool> done(n, false);

    while (completed < n) {
        int idx = -1;
        int min_priority = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (!done[i] && processes[i].at <= time && processes[i].priority < min_priority) {
                min_priority = processes[i].priority;
                idx = i;
            }
        }

        if (idx == -1) {
            ++time;
            continue;
        }

        time += processes[idx].bt;
        processes[idx].ct = time;
        processes[idx].tat = time - processes[idx].at;
        processes[idx].wt = processes[idx].tat - processes[idx].bt;

        total_tat += processes[idx].tat;
        total_wt += processes[idx].wt;
        done[idx] = true;
        ++completed;
    }

    cout << "\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.at << "\t" << p.bt << "\t" << p.priority
            << "\t\t" << p.ct << "\t" << p.tat << "\t" << p.wt << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_wt / n << "\n";
    cout << "Average Turnaround Time: " << total_tat / n << "\n";
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        processes[i].pid = i + 1;
        cout << "Enter arrival time, burst time, and priority for process " << processes[i].pid << ": ";
        cin >> processes[i].at >> processes[i].bt >> processes[i].priority;
    }

    priorityScheduling(processes);
    return 0;
}
*/

/*
Banker AlGO

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int proc, res;

    cout << "Enter number of processes: ";
    cin >> proc;
    cout << "Enter number of res types: ";
    cin >> res;

    vector<vector<int>> alloc(proc, vector<int>(res));
    vector<vector<int>> max(proc, vector<int>(res));
    vector<vector<int>> need(proc, vector<int>(res));
    vector<int> avail(res);

    vector<bool> finished(proc, false); // to track completed processes
    vector<int> safeSequence;

    // Input allocation matrix
    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < proc; i++) {
        cout << "For process P" << i << ": ";
        for (int j = 0; j < res; j++) {
            cin >> alloc[i][j];
        }
    }

    // Input max matrix
    cout << "\nEnter Maximum Matrix:\n";
    for (int i = 0; i < proc; i++) {
        cout << "For process P" << i << ": ";
        for (int j = 0; j < res; j++) {
            cin >> max[i][j];
        }
    }

    // Input available resources
    cout << "\nEnter Available Matrix:\n";
    for (int j = 0; j < res; j++) {
        cin >> avail[j];
    }

    // Calculate need matrix
    for (int i = 0; i < proc; i++) {
        for (int j = 0; j < res; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int count = 0;
    while (count < proc) {
        bool found = false;

        for (int i = 0; i < proc; i++) {
            if (!finished[i]) {
                bool canRun = true;
                for (int j = 0; j < res; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = false;
                        break;
                    }
                }

                if (canRun) {
                    for (int j = 0; j < res; j++) {
                        avail[j] += alloc[i][j];
                    }
                    safeSequence.push_back(i);
                    finished[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found) {
            break; // No process can proceed
        }
    }

    // Final result
    if (count == proc) {
        cout << "\nSystem is in a SAFE state.\n";
        cout << "Safe Sequence: ";
        for (int i = 0; i < proc; i++) {
            cout << "P" << safeSequence[i];
            if (i != proc - 1) cout << " -> ";
        }
        cout << endl;
    }
    else {
        cout << "\nSystem is in an UNSAFE state.\n";
        cout << "Deadlock may occur!" << endl;
    }

    return 0;
}
*/