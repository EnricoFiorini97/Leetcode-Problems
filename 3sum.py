'''
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
'''





class Solution: 
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if nums == []:
            return nums
        
        res = set()
        nums.sort()
        zeroes = nums.count(0)
        
        if zeroes >= 1:            
            if zeroes >= 3:
                res.add((0, 0, 0))
            splitting_idx = nums.index(0)
            for num in nums:
                if num != 0 and num * (-1) in nums:   
                    res.add(tuple(sorted((num, 0, num * -1))))   
        else:
            try:
                splitting_idx = nums.index(min([i for i in nums if i > 0]))
            except:
                return res
            
        negative = nums[: splitting_idx]
        positive = nums[(splitting_idx + zeroes) :]
        
        n = set(negative)
        p = set(positive)
        
        for i in range(len(positive)):
            for j in range(i + 1, len(positive)):
                app = - 1 * (positive[i] + positive[j])
                if app in n:
                    res.add(tuple(sorted([positive[i], positive[j], app])))

        for i in range(len(negative)):
            for j in range(i + 1, len(negative)):
                app = - 1 * (negative[i] + negative[j])
                if app in p:
                    res.add(tuple(sorted([negative[i], negative[j], app])))
                    
        return res
        
        
