#!/usr/bin/env python
# encoding: utf-8

"""

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

"""

class Solution(object):
    def majorityElement(self, nums):
        nums.sort()
        mx, mcn, cn = nums[0], 1, 1
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                cn += 1
            else:
                if cn > mcn:
                    mcn, mx = cn, nums[i-1]
                cn = 1
        if cn > mcn : return nums[-1]
        return mx


# 一次过，效率低
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def fd(a,b):
            if a+1 >= b: return a
            m = (a+b)/2
            p1, p2 = fd(a,m), fd(m+1, b)
            c1, c2 = 0, 0
            for x in range(a, b+1):
                if nums[x] == nums[p1]: c1 += 1
                if nums[x] == nums[p2]: c2 += 1
            return p1 if c1 > c2 else p2
        return nums[fd(0, len(nums)-1)]



