#include<bits/stdc++.h>
using namespace std;

// fibonacci with recursion:
int fibonacci_Rec(int n){

	if(n<=1){
		return n;
	}

	return fibonacci_Rec(n-1) +fibonacci_Rec(n-2);
}

// DP: Recursion + memorisation: Top Down Approach:

int FibDp(int n, vector<int>&dp){

	if(n<=1){
		return n;
	}

	// check after base if element exist in the dp or not:
	if(dp[n]!=-1){
		return dp[n];
	}

	// step2: convert return statement to dp and then return:
	dp[n]= FibDp(n-1,dp)+ FibDp(n-2,dp);
	// return dp
	return dp[n];
}

// DP: tabulation: Bottom Up approch:
int fibdp2(int n, vector<int>& dp){

	// step:02 base case check and change as per requirement:
	dp[0]= 0;
	dp[1]=1;

	// step:03 Loop lage ke aage ka processing 
	for (int i = 2; i <= n; i++)
	{	
		// isko base convert kr denta hai dp me:
		// dp[n]= solve(n-1,dp) + solve(n-2, dp);
		dp[i]= dp[i-1] + dp[ i-2];

	}

	// return fibdp2(n-1,dp) + fibdp2(n-2,dp);
	return dp[n];
	
}

// Space otimization:
int solve(int n, vector<int>dp){

	int prev1=1;
	int prev2=0;

	if(n==0){
		return 0;
	}
	for (int i = 2; i <= n; i++)
	{
		int curr = prev1+ prev2;
		// shift logic:
		prev2= prev1;
		prev1= curr;

	}

	return prev1;
	
}

int main(){

	// 0 1 1 2 3 5 8 13
	int n;
	cout<<"enter the value of n:"<<endl;
	cin>>n;
	// int ans= fibonacci_Rec(n);
	// cout<<"the "<<n+1<<" term of fibonacci series is:"<<ans<<endl;


	// Top down approach: recursion + memoization:
	// step1: Create dp array:
	// vector<int>dp(n+1,-1);
	// int ans = FibDp(n, dp);
	// cout<<ans;


	// Bottom up approach: tabulation:
	// step1: create dp array
	vector<int>dp(n+1);
	int ans = fibdp2(n,dp);
	cout<<ans;
	return 0;
}