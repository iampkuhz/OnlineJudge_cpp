#!/usr/bin/env python
# encoding: utf-8

"""

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
"""


class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        rz, rp = len(nums)-1, len(nums)-1
        zc = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                zc += 1
            else: nums[i-zc] = nums[i]
        for i in range(len(nums) - zc, len(nums)):
            nums[i] = 0

s=Solution()
x=[0,1,0,3,12]
s.moveZeroes(x)
print x



