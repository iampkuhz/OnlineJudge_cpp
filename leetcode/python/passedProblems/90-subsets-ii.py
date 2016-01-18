#!/usr/bin/env python
# encoding: utf-8

"""
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
"""


class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        n = len(nums)
        if not n: return []
        re, ls = [], []
        lastOut = [nums[0] - 1]
        def dfs(tn):
            if tn >= n:
                re.append(ls[:])
                return
            if nums[tn] != lastOut[0]:
                ls.append(nums[tn])
                dfs(tn+1)
                lastOut[0] = ls.pop()
            dfs(tn+1)
        dfs(0)
        return re

s=Solution()
print s.subsetsWithDup([1,2,2])
print s.subsetsWithDup([1,2,3])







