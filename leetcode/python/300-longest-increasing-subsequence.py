#!/usr/bin/env python
# encoding: utf-8


"""
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
"""

# 看答案，O（nlogn）
# 等于怎么办？a<=b,
class Solution(object):
    def lengthOfLIS(self, nums):
        nl = len(nums)
        if nl == 0: return 0
        re = []
        for i in range(0, nl):
            rl = len(re)
            a, b = 0, rl-1
            while a <= b:
                m = (a+b)/2
                if re[m] >= nums[i]: b = m-1
                else: a = m+1
            if a == rl: re.append(nums[i])
            else: re[a] = nums[i]
        return len(re)


# O(n^2)2次过，简单
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # O(n^2)复杂度
        nl = len(nums)
        if nl == 0: return 0
        re = [1] * nl
        rre = 1
        for i in range(1, nl):
            t = 1
            for j in range(0, i):
                if nums[i] > nums[j]:
                    t = max(t, re[j] + 1)
            re[i] = t
            rre = max(rre, re[i])
        return rre


