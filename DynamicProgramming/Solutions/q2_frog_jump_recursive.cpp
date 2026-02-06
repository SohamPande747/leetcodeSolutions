// THIS IS A PLAIN RECURSIVE SOLUTION AND IT WILL GIVE US TLE ERROR 

#include <bits/stdc++.h> 
int func(int idx, vector<int> &heights)
{
    if (idx == 0) return 0;

    int left = func(idx-1, heights) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;

    if (idx > 1) 
    {
        right = func(idx-2, heights) + abs(heights[idx] - heights[idx-2]);
    }

    return min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.

    return func(n-1, heights);
}