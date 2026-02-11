//RECURSION 
class Solution {
public:
    int func(int idx, vector<int>& nums)
    {
        if (idx == 0) return nums[idx];

        if (idx < 0) return 0;

        int pick = nums[idx] + func(idx-2, nums);
        int notPick = func(idx-1, nums);

        return max(pick, notPick); 
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        return func(n-1, nums);    
    }
};

//THIS WILL GIVE TLE ON LEETCODE
