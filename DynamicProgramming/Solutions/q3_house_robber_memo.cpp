//MEMOIZATION
class Solution {
public:
    int func(int idx, vector<int>& nums, vector<int>& dp)
    {
        if (idx < 0) return 0;
        if (idx == 0) return nums[idx];
        if (dp[idx] != -1) return dp[idx];


        int pick = nums[idx] + func(idx-2, nums, dp);
        int notPick = func(idx-1, nums, dp);

        return dp[idx] = max(pick, notPick); 
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        vector<int>dp(n,-1);
        dp[0] = 0;
        return func(n-1, nums, dp);    
    }
};