//THIS IS A MEMOIZATION SOLUTION AND IT WILL NOT GIVE A TLE 

#include <bits/stdc++.h> 
int func(int idx, vector<int> &heights, vector<int> &dp)
{
    if (idx == 0) return 0;

    if (dp[idx] != -1) return dp[idx];
    int left = func(idx-1, heights,dp) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;

    if (idx > 1) 
    {
        right = func(idx-2, heights,dp) + abs(heights[idx] - heights[idx-2]);
    }

    return dp[idx] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    vector<int>dp(n, 0);
    return func(n-1, heights, dp);
}