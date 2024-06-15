#include <bits/stdc++.h>
using namespace std;



/*

*  Leetcode: 377. Combination Sum IV  *

Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The test cases are generated so that the answer can fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
Example 2:

Input: nums = [9], target = 3
Output: 0


*/


class Solution {
public:
    int solveRec(vector<int>&nums, int target){

            // base case:
            if(target<0){
                return 0;
            }

            if(target==0){
                return 1;
            }

            int ans=0;
            for(int i=0; i<nums.size(); i++){

                ans  +=solveRec(nums, target-nums[i]);
            }

            return ans;
    }


    int solveMemo(vector<int>&nums, int target, vector<int>&dp){

            // base case:
            if(target<0){
                return 0;
            }

            if(target==0){
                return 1;
            }

            if(dp[target]!=-1){
                return dp[target];
            }

            int ans=0;
            for(int i=0; i<nums.size(); i++){

                ans  +=solveMemo(nums, target-nums[i],dp);
            }

            dp[target]=ans;
            return dp[target];
    }


    int solveTab(vector<int>&nums, int target){

        vector<int>dp(target+1,0);
        dp[0]=1;
        
        for(int i=1; i<=target; i++){

            long long int ans=0;
            for(int j=0; j<nums.size(); j++){
                if(i-nums[j]>=0){
                      ans  += dp[i-nums[j]];
                }
              
            }

            dp[i]=ans;

        }
        return dp[target];
    }


    int combinationSum4(vector<int>& nums, int target) {
        // return solveRec(nums,target);
        vector<int>dp(target+1,-1);
        // return solveMemo(nums, target, dp);

        return solveTab(nums, target);
    }
};

int main(){



	return 0;
}