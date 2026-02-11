//THIS IS TABULATION BUT WITH A MORE OPTIMIZED SPACE COMPLEXITY ie O(1)

#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    vector<int>dp(n+1, -1);
    
    int past1 = 0;
    int past2 = past1;
    int curr = 0;

    int left = INT_MAX, right = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        left = past1 + abs(heights[i] - heights[i-1]); 

        if (i > 1)
        {
            right = past2 + abs(heights[i] - heights[i-2]); 
        }
        past2 = past1;
        curr = min(left, right);
        past1 = curr;
    }
    return curr;
}