/*WE CAN PICK ANY OF THE EARLIER VARIATION 
AS OUR HELPER BUT THIS WAS TAKEN AS IT THE 
MOST OPTIMAL.WE CAN ALSO TRY TO IMPROVE ITS
SPACE COMPLEXITY BY REDEFINING THE HELPER FUNCTION PARAMETERS */
class Solution {
public:
    int func(vector<int>& nums) 
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
    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        if (n <= 3) return *max_element(nums.begin(), nums.end());

        vector<int>temp1(nums.begin(), nums.begin()+n-1);
        vector<int>temp2(nums.begin()+1, nums.begin()+n);

        return max(func(temp1), func(temp2));
    }
};