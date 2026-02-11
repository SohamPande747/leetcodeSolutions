class Solution {
public:
    //Memoization
    int climbStairs(int n) 
    {
        if (n <= 3) return n;

        int curr = 0;
        int prev1 = 3;
        int prev2 = 2;

        for (int i = 4; i <= n; i++)
        {
            curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }   
        return curr;
    }
};