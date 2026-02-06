//TABULATION WITH SPACE OPTIMAZATION
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        
        int prev2 = nums[0];
        int prev1 = prev2;
        int curr = prev2;
        
        int take = 0, nonTake = 0;
        for (int i = 1; i < n; i++)
        {
            take = nums[i];
            if (i > 1) take += prev2;
            nonTake = prev1;

            curr = max(take, nonTake);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};