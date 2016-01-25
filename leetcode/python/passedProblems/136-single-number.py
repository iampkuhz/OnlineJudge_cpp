#!/usr/bin/env python
# encoding: utf-8

"""

Given an array of integers, every element appears twice except for one. Find that single one.

"""


# Xor 的用法，一次过
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        re = 0
        for x in nums: re ^= x
        return re

