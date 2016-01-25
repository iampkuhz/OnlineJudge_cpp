#!/usr/bin/env python
# encoding: utf-8

"""

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

"""



# 看网上答案,9次过
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        l, r, size = 0, len(nums)-1, len(nums)
        while l < r:
            m = (l+r)/2
            if nums[m] == target: return True
            while l < m and nums[l] == nums[m]:
                l += 1
            if nums[l] < nums[m]:
                if nums[l] <= target < nums[m]:
                    r = m-1
                else: l = m+1
            else:
                if nums[m] < target < nums[r]:
                    l = m+1
                else: r = m-1
        return False
