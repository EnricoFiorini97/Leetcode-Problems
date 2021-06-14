/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
*/

class Solution 
{
    public:
        bool canPartition(vector<int>& nums) 
        {
            int sum = 0;
            
            for (int i = 0; i < nums.size(); ++i)
                sum += nums[i];
 
            if (sum % 2 != 0)
                 return false;
 
            bool part[(sum / 2) + 1][nums.size() + 1];
 
            // initialize top row as true
            for (int i = 0; i <= nums.size(); ++i)
                part[0][i] = true;
 
            // initialize leftmost column,
            // except part[0][0], as 0
            for (int i = 1; i <= sum / 2; ++i)
                part[i][0] = false;
 
            // Fill the partition table in bottom up manner
            for (int i = 1; i <= sum / 2; ++i) 
            {
                for (int j = 1; j <= nums.size(); ++j) 
                {
                    part[i][j] = part[i][j - 1];
                    if (i >= nums[j - 1])
                        part[i][j] = part[i][j] || part[i - nums[j - 1]][j - 1];
                }
            }
 
            return part[sum / 2][nums.size()];
        }
}
