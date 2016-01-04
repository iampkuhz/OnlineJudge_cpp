#!/usr/bin/env python
# encoding: utf-8

"""

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

"""



class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        sz = len(nums)
        if sz < 1 : return False
        l, r = 0, sz-1
        while l <= r:
            m = (l+r)/2
            if nums[m] == target: return True
            if nums[l] <= target < nums[m]:
                r = m-1
            elif nums[r] >= target > nums[m]:
                l = m+1
            else: l += 1
        return False



s=Solution()
print s.search([1,2,3,4,5],1)
print s.search([1,2,3,4,5],5)
print s.search([3,4,5,1,2],3)



