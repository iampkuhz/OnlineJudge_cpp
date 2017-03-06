#!/usr/bin/env python
# encoding: utf-8


"""

Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

"""


# 1次过
class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 1: return 0
        re = nums[0]
        mx, mn = nums[0], nums[0]
        for i in range(1, len(nums)):
            x1, x2 = mx * nums[i], mn * nums[i]
            mx = max(nums[i], max(x1, x2))
            mn = min(x1, min(x2, nums[i]))
            re = max(re, mx)
        return re

