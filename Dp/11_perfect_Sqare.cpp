#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
int solveRec(int n){

     if(n==0){
            return 0;
        }
        int ans = INT_MAX;
        for(int i=1;i*i<=n;  i++){

             ans =min(ans, 1+numSquares(n-i*i) );
        }

        return ans;
}


int solveMemo(int n, vector<int>&dp){

     if(n==0){
            return 0;
        }

        if(dp[n]!=-1) return dp[n];
        int ans = INT_MAX;
        for(int i=1;i*i<=n;  i++){

             ans =min(ans, 1+solveMemo(n-i*i,dp) );
        }

        dp[n]= ans;
        return dp[n];
}


int solveTab(int N){

    vector<int>dp(N+1, 0);
   

    for(int k=1; k<=N; k++){

        int ans = INT_MAX;
        for(int i=1;i*i<=k;  i++){

             ans =min(ans, 1+dp[k-i*i]);
        }
        dp[k]= ans;
    }

    return dp[N];
    
}
    int numSquares(int n) {
        
    //   return solveRec(n);

    //   vector<int> dp(n+1, -1);
    //   return solveMemo(n, dp);

      return solveTab(n);
       
    }
};