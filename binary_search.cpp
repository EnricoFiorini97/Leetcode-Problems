/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

class Solution 
{
    public:
        int binarySearch(vector <int> nums, int x, int start, int end)
        {
            if (end >= start)
            {
                int mid = (start + end) / 2;
                if (nums[mid] == x)         return mid;
                if (nums[mid] > x)          return this->binarySearch(nums, x, start, mid - 1);
                return this->binarySearch(nums, x, mid + 1, end);
            }
            return -1;
        }
    
        int search(vector <int> &nums, int target) 
        {   return this->binarySearch(nums, target, 0, nums.size() - 1); }
};
