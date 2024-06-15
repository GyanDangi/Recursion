#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long int solveRec(int n)
{

    // base caes:
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    long long int ans = (((n - 1)) % MOD * ((solveRec(n - 2)) % MOD + (solveRec(n - 1)) % MOD)) % MOD;
    return ans;
}

long long int solveMemo(int n, vector<long long int> &dp)
{

    // base caes:
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
        return dp[n];

    long long int ans = (((n - 1)) % MOD * ((solveMemo(n - 2, dp)) % MOD + (solveMemo(n - 1, dp)) % MOD)) % MOD;
    dp[n] = ans;
    return dp[n];
}

long long int solveTab(int n)
{

    vector<long long int> dp(n + 1, 0);
    // base caes: anlyze:
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {

        long long int ans = (((i - 1)) % MOD * ((dp[i - 2]) % MOD + (dp[i - 1]) % MOD)) % MOD;

        dp[i] = ans;
    }

    return dp[n];
}

long long int solveSpace(int n)
{

    // base caes: anlyze:
    long long int prev2 = 0;
    long long int prev1 = 1;

    for (int i = 3; i <= n; i++)
    {

        long long int ans = (((i - 1)) % MOD * ((prev2) % MOD + (prev1) % MOD)) % MOD;

        // shifting:
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

long long int countDerangements(int n)
{
    // Write your code here.
    //    return  solveRec(n);

    // Memoization:
    //   vector<long long int> dp(n+1, -1);
    //   return solveMemo((n), dp);

    // return  solveTab(n);

    return solveSpace(n);
}