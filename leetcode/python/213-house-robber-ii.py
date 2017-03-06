#!/usr/bin/env python
# encoding: utf-8


"""
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
"""



# 3次过，都是语法问题，n未定义、[0]*len(nm+1)
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 根据第一个 房间分两种情况讨论
        def find(nm, a, b):
            if a>b : return 0
            re = [0]*(1+len(nm))
            for i in range(a,b+1):
                re[i+1] = max(nm[i]+re[i-1], re[i])
            return re[b+1]

        n = len(nums)
        if len(nums) == 0: return 0
        if len(nums) < 3: return max(nums[0], nums[-1])
        return max(find(nums, 2,n-2)+nums[0], find(nums,1,n-1))


