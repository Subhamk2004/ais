#include <bits/stdc++.h>
using namespace std;

// Structure to represent a Job
struct Job {
    int id;          // Job ID
    int deadline;    // Deadline of job
    int profit;      // Profit earned from job
};

// Comparison function for sorting jobs based on profit (descending)
bool compareJobs(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to find the maximum profit sequence of jobs
void scheduleJobs(vector<Job>& jobs) {
    // Sort jobs based on profit in non-increasing order
    sort(jobs.begin(), jobs.end(), compareJobs);
    
    // Find the maximum deadline
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }
    
    // Initialize the result array and slot array
    vector<int> result(maxDeadline, -1);  // Stores job IDs scheduled at each slot
    vector<bool> slot(maxDeadline, false); // To track if a time slot is filled
    
    // Process jobs one by one for optimal profit within deadlines
    int optimalJobsScheduled = 0;
    int optimalProfit = 0;
    vector<int> scheduledJobIds;
    
    for (const Job& job : jobs) {
        // Find a free slot for this job
        // Start from the last possible slot
        for (int i = min(maxDeadline, job.deadline) - 1; i >= 0; i--) {
            // If slot is empty
            if (!slot[i]) {
                result[i] = job.id;
                slot[i] = true;
                optimalJobsScheduled++;
                optimalProfit += job.profit;
                scheduledJobIds.push_back(job.id);
                break;
            }
        }
    }
    
    // Create a complete execution sequence including all jobs
    // First include optimally scheduled jobs
    vector<int> executionOrder = scheduledJobIds;
    
    // Then add remaining jobs that couldn't be scheduled optimally
    for (const Job& job : jobs) {
        if (find(executionOrder.begin(), executionOrder.end(), job.id) == executionOrder.end()) {
            executionOrder.push_back(job.id);
        }
    }
    
    // Print optimally scheduled jobs within deadlines
    cout << "\nOptimally Scheduled Jobs (within deadlines): ";
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << "\nOptimal Number of Jobs Scheduled: " << optimalJobsScheduled;
    cout << "\nOptimal Profit: " << optimalProfit << endl;
    
    // Print complete execution order for all jobs
    cout << "\nComplete Execution Order (all jobs): ";
    for (int jobId : executionOrder) {
        cout << jobId << " ";
    }
    cout << "\nTotal Number of Jobs: " << jobs.size() << endl;
    
    // Print jobs that will miss their deadlines
    cout << "\nJobs that will miss their deadlines: ";
    int missedDeadlines = 0;
    for (int i = optimalJobsScheduled; i < executionOrder.size(); i++) {
        cout << executionOrder[i] << " ";
        missedDeadlines++;
    }
    
    if (missedDeadlines == 0) {
        cout << "None (all jobs can meet their deadlines)";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    
    vector<Job> jobs(n);
    
    cout << "Enter job details (ID, Deadline, Profit):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Job " << i + 1 << ": ";
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    
    cout << "\nJob Details:";
    cout << "\nID\tDeadline\tProfit";
    for (int i = 0; i < n; i++) {
        cout << "\n" << jobs[i].id << "\t" << jobs[i].deadline << "\t\t" << jobs[i].profit;
    }
    
    scheduleJobs(jobs);
    
    return 0;
}