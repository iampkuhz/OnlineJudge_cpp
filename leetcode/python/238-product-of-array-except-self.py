#!/usr/bin/env python
# encoding: utf-8


"""
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
"""

# 2次过，看答案
class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nl = len(nums)
        if nl < 2: return nums
        out = [1] * nl
        for i in range(1, nl):
            out[i] = out[i-1] * nums[i-1]
        for i in range(nl-2, -1, -1):
            nums[i] *= nums[i+1]
        for i in range(nl-1):
            out[i] *= nums[i+1]
        return out
