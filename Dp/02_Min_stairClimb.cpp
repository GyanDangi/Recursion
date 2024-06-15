#include <bits/stdc++.h>
using namespace std;

// minimum cost to reach to destination: we can start from 0th stair or 1st stair:


class Solution {
public:
    int solve(vector<int>&cost, int n){

        // base case:
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }

         int ans= cost[n]+ min(solve(cost, n-1), solve(cost, n-2));
        return ans;
    }
    int solve2(vector<int>&cost, int n,vector<int>&dp){

        // base case:
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }

        // step:03
        if(dp[n]!=-1){
            return dp[n];
        }
        // step2: chage return function dp:
         dp[n]= cost[n]+ min(solve2(cost, n-1,dp), solve2(cost, n-2,dp));
        return dp[n];
    }

    // tabulation:
    int solve3(vector<int>& cost, int n, vector<int>&dp){


        // step2:
        dp[0]= cost[0];
        dp[1]= cost[1];

        // step:03
        for(int i=2; i<n; i++){
            dp[i]= cost[i] + min(dp[i-1],dp[i-2]);
        }

        return min(dp[n-1],dp[n-2]);
    }

    int solve4(vector<int>& cost, int n){

         int prev1= cost[1];
         int prev2= cost[0];

        for(int i=2; i<n; i++){
            int curr= cost[i]+ min(prev2, prev1);
            prev2= prev1;
            prev1= curr;
        }

        return min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        // int ans= min(solve(cost, n-1), solve(cost,n-2));
        // return ans;

        // step:01
        // vector<int>dp(n+1,-1);
        // int ans= min(solve2(cost, n-1,dp), solve2(cost,n-2,dp));
        // return ans;

        // tabulation:
        //  vector<int>dp(n+1);
        // int ans= solve3(cost,n, dp);
        // return ans;

        return solve4(cost, n);
    }
};

int main(){



	return 0;
}