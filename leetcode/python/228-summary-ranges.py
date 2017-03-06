#!/usr/bin/env python
# encoding: utf-8



"""
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
"""


# 1次过
class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        nl = len(nums)
        if nl == 0:return []
        ls, le = nums[0], nums[0]
        re = []
        def p(ls, le):
            if ls == le: re.append(str(ls))
            else: re.append(str(ls) + "->" + str(le))
        for i in range(1, nl):
            if nums[i] == le + 1: le += 1
            else:
                p(ls, le)
                ls = le = nums[i]
        p(ls, le)
        return re


