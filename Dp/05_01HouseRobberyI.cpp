#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

int solveRec(vector<int>&nums, int index){

    // base case:
    if(index>=nums.size()){
        return 0;
    }

    int inc= nums[index] + solveRec(nums, index+2);
    int exc= 0 + solveRec(nums, index+1);

    return max(inc, exc);
}


int solveMemo(vector<int>&nums, int index, vector<int>&dp){

    // base case:
    if(index>=nums.size()){
        return 0;
    }

    if(dp[index]!= -1){
        return dp[index];
    }

    int inc= nums[index] + solveMemo(nums, index+2,dp);
    int exc= 0 + solveMemo(nums, index+1,dp);

    dp[index] =max(inc, exc);
    return dp[index];
}



int solveTab(vector<int>&nums){
    int n= nums.size();
    vector<int>dp(n+1,0);

    for(int i=0; i<n; i++){
        int inc= nums[i]+ dp[i+2];
        int exc= 0+ dp[i+1];

        dp[i] =max(inc,exc);
    }
    return dp[n-1];
}

int solveSpace(vector<int>nums){
    int n= nums.size();
    int prev2=0;
    int prev1=nums[0];


    for(int i=1; i<n; i++){
        int inc= nums[i]+ prev2;
        int exc= 0+ prev1;
        int ans= max(inc, exc);
        prev2= prev1; 
        prev1= ans;
    }
    return prev1;
}

    int rob(vector<int>& nums) {
        int n = nums.size();
        // int ans = solveRec(nums,0);
        // return ans;

        // vector<int>dp(n+2,-1);
        // int ans = solveMemo(nums,0,dp);
        // return ans;
        

        return solveSpace(nums);
        
    }
};