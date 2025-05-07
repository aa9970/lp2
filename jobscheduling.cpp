#include <iostream>
using namespace std;

#define MAX_N 100

struct Job {
    char id;    
    int dead;   
    int profit; 
};

void sortJobs(Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

void jobScheduling(Job jobs[], int n) {
    int maxDead = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].dead > maxDead) {
            maxDead = jobs[i].dead;
        }
    }

    char slot[MAX_N] = {'\0'};
    int totalProfit = 0;

    sortJobs(jobs, n);

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].dead - 1; j >= 0; j--) {
            if (slot[j] == '\0') { 
                slot[j] = jobs[i].id; 
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 0; i < maxDead; i++) {
        if (slot[i] != '\0') {
            cout << slot[i] << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;
    Job jobs[MAX_N];

    cout << "Enter number of jobs: ";
    cin >> n;

    cout << "Enter jobs (ID deadline profit, e.g., A 2 50):\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].dead >> jobs[i].profit;
    }

    jobScheduling(jobs, n);

    return 0;
}