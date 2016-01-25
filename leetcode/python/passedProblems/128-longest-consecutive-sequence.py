#!/usr/bin/env python
# encoding: utf-8

"""
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.



"""


# 看答案，使用Set删除元素, 56ms
class Solution(object):
    def longestConsecutive(self, nums):
        nums = set(nums)
        re = 0
        while nums:
            stk = [next(iter(nums))]
            tmp = 0
            while stk:
                tmp += 1
                cur = stk.pop()
                nums.discard(cur)
                if cur + 1 in nums: stk.append(cur + 1)
                if cur - 1 in nums: stk.append(cur - 1)
            re = max(re, tmp)
        return re


# 看答案，使用字典, 56ms
class Solution(object):
    def longestConsecutive(self, nums):
        nlen = len(nums)
        dic = {}
        re = 0
        for n in nums:
            if n in dic: continue
            left, right = 0, 0
            le = 1
            if n-1 in dic:
                left = dic[n-1]
                le += left
            if n+1 in dic:
                right = dic[n+1]
                le += right
            dic[n] = 1
            dic[n-left] = le
            dic[n+right] = le
            re = max(re, le)
        return re


# 非O（n）的算法也可以过。。。,52ms
class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        re = 1; i, slen = 0, len(nums)
        while i < slen:
            j = i
            dup = 0
            while j < slen -1 and nums[j] >= nums[j+1] -1:
                if nums[j] == nums[j+1]: dup += 1
                j += 1
            re = max(re, j-i+1 - dup)
            i = j + 1
        return re
