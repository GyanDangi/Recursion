#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &nums, int index)
{

	if (index < 0)
	{
		return 0;
	}

	if (index == 1)
	{
		return nums[0];
	}

	// include:
	int inc = solveRec(nums, index - 2) + nums[index];
	// exclude:
	int exc = solveRec(nums, index - 1) + 0;

	return max(inc, exc);
}

int solveMemo(vector<int> &nums, int index, vector<int> &dp)
{

	if (index < 0)
	{
		return 0;
	}

	if (index == 1)
	{
		return nums[0];
	}

	// step:03:
	if (dp[index] != -1)
	{
		return dp[index];
	}

	// include:
	int inc = solveMemo(nums, index - 2, dp) + nums[index];
	// exclude:
	int exc = solveMemo(nums, index - 1, dp) + 0;

	// step:02 store and in dp:
	dp[index] = max(inc, exc);
	return dp[index];
}

int solveTab(vector<int> &nums)
{

	// step 01: dp creation
	int n = nums.size();
	vector<int> dp(n, 0);

	// step:02 base case analyze
	dp[0] = nums[0];

	// step:03 for loop handle:

	for (int i = 1; i < n; i++)
	{
		int inc = dp[i-2]+ nums[i];
		// exclude:
		int exc = dp[i-1] +0;

		// step:02 store and in dp:
		dp[i] = max(inc, exc);
		
	}

	return dp[n-1];
}


int solveSpaceOpt(vector<int>&nums){
	int n= nums.size();

	int prev2=0;
	int prev1=nums[0];

	for (int i = 1; i <n; i++)
	{
		int inc = prev2+ nums[i];
		// exclude:
		int exc = prev1 +0;

		// step:02 store ans and handle perv1 and prev2
		int ans= max(prev1, prev2);
		prev2= prev1;
		prev1= ans;
	}
	
	return prev1;
}

int main()
{

	// vector<int>nums = {9,9,8,2};
	// int size= nums.size();
	// int ans= solveRec(nums, size-1);
	// cout<<"The maximum sum of the non-adjacent element is:"<<ans;

	// Recursion+ memoization:
	// vector<int> nums = {9, 9, 8, 2};
	// int size = nums.size();
	// // step:01 dp creation and pass to function:
	// vector<int> dp(size + 1, -1);
	// int ans = solveMemo(nums, size - 1, dp);
	// cout << ans;


	vector<int> nums = {9, 9, 8, 2};
	int ans = solveTab(nums);
	cout<<ans;


	// space otimization:
	// vector<int> nums = {9, 9, 8, 2};
	// int ans = solveSpaceOpt(nums);
	// cout<<ans;

	return 0;
}