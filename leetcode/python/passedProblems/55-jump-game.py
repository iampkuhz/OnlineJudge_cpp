#!/usr/bin/env python
# encoding: utf-8

"""

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

"""
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        dis = 0
        for i in range(len(nums)):
            if i > dis:
                return False;
            dis = max(dis, nums[i] + i)
        return True;

s=Solution()
print s.canJump([2,3,1,1,4])
print s.canJump([3,2,1,0,4])

