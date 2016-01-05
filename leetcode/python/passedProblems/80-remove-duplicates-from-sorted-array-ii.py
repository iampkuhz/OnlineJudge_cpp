#!/usr/bin/env python
# encoding: utf-8

"""
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question
"""


class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sz = len(nums)
        if sz == 0:
            return 0
        last, dup = nums[0], False
        re = 1
        for i in range(1, sz):
            if nums[i] != last or (nums[i] == last and not dup):
                nums[re] = nums[i]
                re += 1
                if nums[i] != last:
                    last = nums[i]; dup = False
                else: dup = True
        return re

