#!/usr/bin/env python
# encoding: utf-8

"""
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
"""
class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for j  in range(len(nums)):
            i = j;
            while nums[i] != i+1 and nums[i] >0 and nums[i] <= len(nums) and nums[nums[i]-1] != nums[i]:
                tmp  = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = tmp;

        for i in range(len(nums)):
            if nums[i] != i+1:
                return i+1;
        return len(nums)+1;

s = Solution();
print s.firstMissingPositive([1,2,0]);
print s.firstMissingPositive([3,4,-1,1]);

