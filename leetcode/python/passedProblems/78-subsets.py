#!/usr/bin/env python
# encoding: utf-8

"""

Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
"""


class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        re, sset = [], []
        sz = len(nums)
        if sz == 0: return re
        nums.sort()
        def find(ind):
            if ind >= sz:
                re.append(sset[:])
                return
            sset.append(nums[ind])
            find(ind+1)
            sset.pop()
            find(ind+1)
        find(0)
        return re

s=Solution()
print s.subsets([1,2,3])



