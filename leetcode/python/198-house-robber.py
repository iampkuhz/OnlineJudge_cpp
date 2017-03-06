#!/usr/bin/env python
# encoding: utf-8



"""
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
"""


# 1次过
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        if l < 2: return 0 if l == 0 else nums[0]
        re = [0 for i in range(l+1)]
        re[0], re[1] = nums[0], max(nums[0], nums[1])
        for i in range(2, l):
            re[i] = max(nums[i] + re[i-2], re[i-1])
        return re[l-1]


