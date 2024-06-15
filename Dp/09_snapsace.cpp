#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &val, vector<int> &wt, int index, int capacity)
{

	if (index >= val.size() || capacity == 0)
	{
		return 0;
	}

	int inc = 0;
	if (capacity >= wt[index])
	{
		inc = val[index] + solveRec(val, wt, index + 1, capacity - wt[index]);
	}

	int exc = 0 + solveRec(val, wt, index + 1, capacity);

	return max(inc, exc);
}

int solveMemo(vector<int> &val, vector<int> &wt, int index, int capacity, vector<vector<int>> &dp)
{

	if (index >= val.size() || capacity == 0)
	{
		return 0;
	}
	if (dp[index][capacity] != -1)
		return dp[index][capacity];

	int inc = 0;
	if (capacity >= wt[index])
	{
		inc = val[index] + solveMemo(val, wt, index + 1, capacity - wt[index], dp);
	}

	int exc = 0 + solveMemo(val, wt, index + 1, capacity, dp);

	dp[index][capacity] = max(inc, exc);
	return dp[index][capacity];
}

int solveTab(vector<int>&val, vector<int>&wt, int index, int capacity)
{
	int n = val.size();
	vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

	int inc = 0;
	for (int index = n - 1; index >= 0; index--)
	{
		for (int c = 0; c <= capacity; c++)
		{
			int inc = 0;
			if (c >= wt[index])
			{
				inc = val[index]  + dp[index + 1][ c - wt[index]];
			}

			int exc = 0 + dp[ index + 1][c];

			dp[index][c] = max(inc, exc);
			
		}
	
	}

	return dp[0][capacity];
}


int main()
{
	int n = 3;
	vector<int> val = {60, 100, 120};
	vector<int> wt = {10, 20, 30};
	int capacity = 50;
	// int ans= solveRec(val, wt, 0, capacity);
	// cout<<ans;

	// vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
	// int ans = solveMemo(val, wt, 0, capacity, dp);

	// cout << ans;
	cout<<solveTab(val,wt,0,capacity);

	return 0;
}