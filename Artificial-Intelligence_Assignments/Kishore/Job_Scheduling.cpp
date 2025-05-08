#include<bits/stdc++.h>
using namespace std;


struct Job{
    int id,deadline,profit;
};

bool compare(Job a, Job b){
   return a.profit> b.profit;
}
void jobschedule(vector<Job>& jobs){
  
  sort(jobs.begin(),jobs.end(),compare);
  
  // for(auto it:jobs){
  //   cout<<it.profit<<" ";
  // }
   int max_dead=0;
   
   for(auto it:jobs){
     max_dead = max(max_dead,it.deadline);
   }
   cout<<max_dead<<endl;
    vector<bool> timeslots(max_dead+1,true);
    vector<Job> scheduledjobs;
    for(auto it:jobs){
      for(int j=it.deadline;j>=1;j--){
        if(timeslots[j]){
          scheduledjobs.push_back(it);
          timeslots[j]  = false;
          break;
          // this break is important because we need to break the loop once we find a free slot
          // if we didn't break the loop then we will get the last free slot and we will not be able to schedule the job
          // if we didn't breal then we won't get the latest free time 
          // availabel so we need to break the loop to get the latest possible time availabel for us lese we will get the last time slot availabel
          // and we will not be able to schedule the job correctly.
        }
      }
    }
    
    int max_profit=0;
    for(auto it:scheduledjobs){
      cout<<it.id<<" ";
      max_profit+= it.profit;
    }
    cout<<endl;
    cout<<max_profit<<endl;
}


int main(){
  vector<Job> jobs{
        {1, 4, 20}, // Job 1: deadline 4, profit 20
        {2, 1, 10}, // Job 2: deadline 1, profit 10
        {3, 1, 40}, // Job 3: deadline 1, profit 40
        {4, 1, 30}, // Job 4: deadline 1, profit 30
        {5, 2, 50}, // Job 5: deadline 2, profit 50
        {6, 3, 15}, // Job 6: deadline 3, profit 15
        {7, 2, 25}  // Job 7: deadline 2, profit 25
};

  jobschedule(jobs);
   return 0;
  
}



// #include <iostream>
// #include <algorithm>
// using namespace std;

// struct Job {
//     int id;
//     int deadline;
//     int profit;
// };

// bool compare(Job a, Job b) {
//     return a.profit > b.profit; // Higher profit first
// }

// void jobScheduling(Job jobs[], int n) {
//     sort(jobs, jobs + n, compare);
//     vector<bool> timeSlot(n,false);// Slot availability
//     int jobResult[n];            // Store selected jobs

//     for (int i = 0; i < n; i++) {
//         // Try to place the job at the latest free slot before its deadline
//         for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
//             if (!timeSlot[j]) {
//                 timeSlot[j] = true;
//                 jobResult[j] = i; // Store job index
//                 break;
//             }
//         }
//     }

//     // Output selected jobs in order of time slot
//     for (int i = 0; i < n; i++) {
//         if (timeSlot[i])
//             cout << jobs[jobResult[i]].id << " ";
//     } cout<<endl;
//     int profit=0;
//     for (int i = 0; i < n; i++) {
//         if (timeSlot[i])
//     profit+=  jobs[jobResult[i]].profit ;
//     }
//     cout<<profit<<endl;
// }

// int main() {
//     Job jobs[] = {
//         {1, 4, 20},
//         {2, 1, 10},
//         {3, 1, 40},
//         {4, 1, 30}
//     };
//     int n = sizeof(jobs) / sizeof(jobs[0]);

//     jobScheduling(jobs, n);
//     for(int i=0;i<n;i++){
//         cout<<jobs[i].profit<<" ";
//     }
//     cout<<endl;

    
//     return 0;
// }
