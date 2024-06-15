#include<limits.h>
#include <bits/stdc++.h>
using namespace std;

int solveRec(int n, int x, int y, int z){

	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}

	int a = solveRec(n-x, x, y, z) +1;
	int b = solveRec(n-y, x, y, z) +1;
	int c=  solveRec(n-z, x, y, z) +1;

	int ans= max(a, max(b,c));
	return ans;
}


int solveMemo(int n, int x, int y, int z,vector<int>&dp){

	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	if(dp[n]!=-1){
		return dp[n];
	}

	int a = solveMemo(n-x, x, y, z,dp) +1;
	int b = solveMemo(n-y, x, y, z,dp) +1;
	int c=  solveMemo(n-z, x, y, z,dp) +1;

	dp[n]= max(a, max(b,c));
	return dp[n];
}

int solveTab(int n, int x, int y, int z){

	vector<int>dp(n+1,INT_MIN);
	dp[0]=0;
	for(int i=1; i<=n; i++){

		// sab ka alag alag nikal ke krna hai:
		if((i-x>=0) && (i-y>=0) &&( i-z>=0)){

			int a = dp[i-x] +1;
			int b = dp[i-y] +1;
			int c=  dp[i-z] +1;

		dp[i]= max(a, max(b,c));

		}
		
	}

	return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

	// int ans = solve(n, x, y, z);

	// step01: create dp;
	// vector<int> dp(n+1, -1);
	// int ans = solveMemo( n, x, y, z, dp);

	int ans = solveTab( n, x, y, z);
	if(ans<0){
		return 0;
	}
	else{
		return ans;
	}
}