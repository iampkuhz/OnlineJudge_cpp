#!/usr/bin/env python
# encoding: utf-8

"""
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
"""



# 1次过
class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def getm(a,b):
            if a+1 >= b: return min(nums[a], nums[b])
            if nums[a] < nums[b]: return nums[a]
            m = (a+b)/2
            if nums[m] > nums[a]: return getm(m+1, b)
            return getm(a+1, m)
        return getm(0, len(nums)-1)

