#!/usr/bin/env python
# encoding: utf-8

"""
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
"""

# 看的答案，不过时间并没有提升，都是44ms
class Solution(object):
    def sortColors(self, nums):
        l1, l0, r2, t = 0, 0, len(nums)-1, len(nums)
        for i in xrange(t):
            ni = nums[i]
            nums[i] = 2
            if ni < 2:
                nums[l1], l1 = 1, l1 + 1
            if ni == 0:
                nums[l0], l0 = 0, l0 + 1




# 左右两个指针分别指向0,2的边界
class Solution(object):
    def sortColors(self, nums):
        lp, rp, ln, t = 0, len(nums)-1, len(nums), 0
        while t <= rp:
            if nums[t] == 0:
                nums[lp], lp = 0, lp + 1
            elif nums[t] == 2:
                nums[t] = nums[rp]; nums[rp], rp = 2, rp - 1
                continue
            t = t + 1
        for i in range(lp, rp+1):
            nums[i] = 1

#class Solution(object):
#    def sortColors(self, nums):
#        """
#        :type nums: List[int]
#        :rtype: void Do not return anything, modify nums in-place instead.
#        """
#        cnt1, cnt3 = 0, 0
#        for ni in nums:
#            if ni == 0:
#                cnt1 += 1
#            elseif ni == 2:
#                cnt3 += 1
#        for i in range(len(nums)):
#            if i < cnt1:
#                nums[i] = 0
#            elif i >= len(nums) - cnt3:
#                nums[i] = 2
#            else:
#                nums[i] = 1







