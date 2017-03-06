#!/usr/bin/env python
# encoding: utf-8


"""
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implem
"""


# 1次过
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nl = len(nums)
        if nl < 1: return 0
        s = sum(nums)
        return (nl+1)*(nl)/2 - s

