argus@pop-os:~/Documents/AI/3_Greedy_Search$ g++ JobScheduling.cpp
argus@pop-os:~/Documents/AI/3_Greedy_Search$ ./a.out
Enter the number of jobs: 5
Enter job details (ID, Deadline, Profit):
Job 1: 1 2 100
Job 2: 2 1 19
Job 3: 3 2 27
Job 4: 4 1 25
Job 5: 5 3 15

Job Details:
ID      Deadline        Profit
1       2               100
2       1               19
3       2               27
4       1               25
5       3               15
Optimally Scheduled Jobs (within deadlines): 3 1 5 
Optimal Number of Jobs Scheduled: 3
Optimal Profit: 142

Complete Execution Order (all jobs): 1 3 5 4 2 
Total Number of Jobs: 5

Jobs that will miss their deadlines: 4 2 




Explanation of the Changes

Tracking Optimal Schedule:

We still use the greedy approach to identify the jobs that can be scheduled within their deadlines to maximize profit.
We keep track of these optimally scheduled jobs in a separate list.


Complete Execution Order:

After determining the optimal schedule, we create a complete execution order.
The optimally scheduled jobs come first (in the order they were scheduled).
Then we add any remaining jobs that couldn't fit within their deadlines.


Deadline Information:

The program now explicitly shows which jobs will miss their deadlines.
These are the jobs that appear after the optimally scheduled jobs in the execution order.


Comprehensive Output:

The output now provides both the optimal schedule (jobs within deadlines) and the complete execution sequence (all jobs).