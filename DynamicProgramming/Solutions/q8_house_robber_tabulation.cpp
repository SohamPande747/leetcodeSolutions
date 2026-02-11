//TABULATION
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n,-1);
        dp[0] = nums[0];
        
        int take = 0, nonTake = 0;
        for (int i = 1; i < n; i++)
        {
            take = nums[i];
            if (i > 1) take += dp[i-2];
            nonTake = dp[i-1];

            dp[i] = max(take, nonTake);
        }
        return dp[n-1];
    }
};