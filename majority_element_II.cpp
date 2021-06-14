/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?
*/


class Solution 
{
    public:
        vector<int> majorityElement(vector<int>& nums) 
        {
            vector <int> res;   map <int, int> hmap;
            
            for (auto itr: nums)
                if (hmap.find(itr) == hmap.end())       hmap[itr] = 1;
                else                                    ++hmap[itr];
            
            for (auto itr: hmap)
                if (itr.second > (nums.size() / 3))   res.push_back(itr.first);
            
            return res;
        }
};








