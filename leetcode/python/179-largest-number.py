#!/usr/bin/env python
# encoding: utf-8

"""
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
"""

# 提交12次，各种情况没考虑到，python自定义函数不会写，排序的方向，判断的终止条件
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        if len(nums) < 1: return ""
        def cpr2(i1, i2):
            s1, s2 = str(i1), str(i2)
            l1, l2 = len(s1), len(s2)
            t1, t2 = -1, -1
            while True:
                t1, t2 = (t1+1)%l1, (t2+1)%l2
                if s2[t2] > s1[t1]: return 1
                elif s2[t2] < s1[t1]: return -1
                if t1 == l1-1 and t2 == l2-1: return 0
        nums.sort(cpr2)
        #print nums
        i = -1
        re = "".join(str(x) for x in nums)
        while i + 2 < len(re) and re[i+1] == '0':
            i += 1
        return re[i+1:]

