#!/usr/bin/env python
# encoding: utf-8


"""
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
"""


# 5次过，r-l 写成r+l, r初始错写0，sm多-=nums[l]
class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        l, r, ln = 0, -1, len(nums)
        if ln < 1: return 0
        sm = 0
        re = 0
        while r < ln-1:
            r += 1
            sm += nums[r]
            if sm >= s:
                while sm >= s and l <= r:
                    l, sm = l+1, sm - nums[l]
                re = r-l+2 if re == 0 or r-l+2<re else re
        return re



