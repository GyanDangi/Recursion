#include <bits/stdc++.h>
using namespace std;

/*
LeetCode:300 Dp se solve honga nhi to Binary Serach se solve 
recursion se Time limit exceed aa jayenga:

recursion solution :

Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1


*/

// Recursion solution:
int solve(int*arr,int size, int curr, int prev){

    //base case:
    if(curr==size){
        return 0;
    }
    // include:
    int  pick=0;
    if(prev==-1 || arr[curr]>arr[prev]){
        pick =1+solve(arr,size, curr+1, curr);
    }
    // exclude:
    int notpick= 0+solve(arr,size, curr+1, prev);
    return max(pick,notpick);
}

int main(){
    int arr[6]={0,0,0,0,0,0};
    int nums[8] = {10,9,2,5,3,7,101,18};
    int size1=8;
    int size=6;
    int curr=0;
    int prev=-1;
    int ans= solve(arr, size, curr, prev);
    int ans1= solve(nums, size1, curr, prev);
    cout<<ans1<<endl;
    cout<<ans<<endl;
    return 0;
}