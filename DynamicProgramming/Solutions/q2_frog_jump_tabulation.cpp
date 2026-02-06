//THIS IS TABULATION BASED SOLUTION, THE BOTTOM UP APPROACH

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    vector<int>dp(n+1, -1);
    
    dp[0] = 0;

    int left = INT_MAX, right = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        left = dp[i-1] + abs(heights[i] - heights[i-1]); 

        if (i > 1)
        {
            right = dp[i-2] + abs(heights[i] - heights[i-2]); 
        }

        dp[i] = min(left, right);
    }
    return dp[n-1];
}