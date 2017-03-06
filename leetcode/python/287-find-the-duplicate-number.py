#!/usr/bin/env python
# encoding: utf-8


"""
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

"""

# 看答案， 52ms
class Solution(object):
    def findDuplicate(self, nums):
        newt, fast, slow = 0, 0, 0
        while True:
            fast = nums[nums[fast]]
            slow = nums[slow]
            if fast == slow:
                while newt != slow:
                    newt, slow = nums[newt], nums[slow]
                return newt


# 看答案 144ms
class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a, b = 1, len(nums)-1
        while a +1 < b:
            m = (a+b)/2
            cnt1, cnt2, cntm = 0, 0, 0
            for i in range(len(nums)):
                if nums[i] == m: cntm += 1
                elif nums[i] > m and nums[i] <= b: cnt2 += 1
                elif nums[i] < m and nums[i] >= a: cnt1 += 1
            if cntm > 1: return m
            elif cnt1 > m-a: b = m-1
            else: a = m+1
        ca, cb = 0, 0
        for x in nums:
            if x == a: ca += 1
            if x == b: cb += 1
        if ca > 1: return a
        return b


