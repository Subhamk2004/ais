#include<bits/stdc++.h>
using namespace std;
// Function to perform selection sort
void selection_sort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        int mini =i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[mini]){
                mini =j;
            }
        
        }
        // I made the mistake here so be careful and put the swapp condition 
        // outside the inner loop  not inside the inner loop.
        swap(arr[i],arr[mini]);
    }
}

int main(){
    int n;cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}