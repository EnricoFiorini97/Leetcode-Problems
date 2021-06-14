/*
Given an unsorted integer array nums, find the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.
*/


/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) 
{
    nums = nums.filter(n => n > 0);
    
    for(let i = 0; i<nums.length;i++)
    {
	    let index = Math.abs(nums[i]) - 1;
	    if(index >= nums.length)        continue;
        nums[index]= - Math.abs(nums[index]);
	}
	
    for(let i = 0; i< nums.length;i++)
	    if(nums[i] > 0)                 return i + 1;

    return nums.length + 1;
};


