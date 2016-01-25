#!/usr/bin/env python
# encoding: utf-8


"""
Given an array of integers, every element appears three times except for one. Find that single one.
"""

# 看答案
class Solution(object):
    def singleNumber(self, nums):
        return (sum(list(set(nums)) * 3 - sum(nums))) / 2

# 一次过，速度可以提升
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        x=set()
        dx=set()

        for i in nums:
            if i not in dx:
                if i not in x:
                    x.add(i)
                else:
                    x.remove(i)
                    dx.add(i)
        return next(iter(x))
