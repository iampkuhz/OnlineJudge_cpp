#!/usr/bin/env python
# encoding: utf-8


"""
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
"""


# 1次过
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        p = [[nums[i],i] for i in range(len(nums))]
        def myCmp(p1, p2):
            if p1[0] > p2[0]: return 1
            elif p1[0] < p2[0]: return -1
            return 1 if p1[1] > p2[1] else (-1 if p1[1] < p2[1] else 0)
        p.sort(cmp = myCmp)
        for i in range(0, len(nums)-1):
            if p[i][0] == p[i+1][0] and p[i+1][1] - p[i][1] <= k:
                return True
        return False


