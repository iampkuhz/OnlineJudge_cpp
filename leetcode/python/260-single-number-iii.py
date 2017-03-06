#!/usr/bin/env python
# encoding: utf-8


"""
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
"""


# 看答案, 3次过， 1：<<= 2:a,b=0
class Solution(object):
    def singleNumber(self, nums):
        xor = 0
        for x in nums: xor ^= x
        a, b = 0, 0
        tag = 1
        while tag & xor == 0: tag <<= 1
        for x in nums:
            if x & tag == 0: a ^= x
            else: b ^= x
        return [a, b]

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # 不符合规定,但是能过，1次过
        nums.sort()
        re = []
        if nums[0] != nums[1]: re.append(nums[0])
        for i in range(1, len(nums)-1):
            if nums[i] != nums[i-1] and nums[i] != nums[i+1]: re.append(nums[i])
        if nums[len(nums)-1] != nums[len(nums)-2]: re.append(nums[len(nums)-1])
        return re

