
/*
Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.
*/



class Solution 
{
    public:
        int pivotIndex(vector<int>& nums) 
        {
            if (nums.empty() ||  nums.size() < 3)
                return -1;
            
            vector <int> dp(nums.size(), 0);
            dp[0] = nums[0];
            
            for (int i = 1; i < nums.size(); ++i)
                dp[i] = nums[i] + dp[i - 1];
            
            if (dp[0] == dp[nums.size() - 1])
                return 0;
            
            for (int i = 1; i < dp.size(); ++i)
                if (dp[i - 1] == (dp[dp.size() - 1]) - dp[i])
                    return i;
            
            return -1;
        }
};
