#!/usr/bin/env python
# encoding: utf-8


"""

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Show Hint
"""

#
class Solution(object):
    def majorityElement(self, nums):
        # 非要求，map做
        nl = len(nums)
        if nl == 0: return []
        nf = {}
        for x in nums:
            if x not in nf: nf[x] = 1
            else: nf[x] += 1
        re = []
        for x in nf:
            if nf[x] > nl/3: re.append(x)
        return re


class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # 非要求，快排+统计
        nl = len(nums)
        if nl == 0: return []
        nums.sort()
        cx, vi = 1, nums[0]
        re = []
        for i in range(1, nl):
            if nums[i] == vi: cx += 1
            else:
                if cx > nl/3: re.append(vi)
                vi, cx = nums[i], 1
        if cx > nl/3: re.append(vi)
        return re

