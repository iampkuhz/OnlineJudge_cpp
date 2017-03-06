#!/usr/bin/env python
# encoding: utf-8


"""
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

"""


# 根据快排的保序性，3次过
class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # 自己实现一个cmp函数
        def mcmp(p1, p2):
            if p1 == p2: return 0
            if p1 == 0: return 1
            if p2 == 0: return -1
            return 0
        nums.sort(cmp = mcmp)


