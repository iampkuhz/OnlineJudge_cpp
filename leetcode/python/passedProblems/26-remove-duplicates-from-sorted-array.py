#-*-coding:utf-8-*-
"""
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
"""
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums);
        last = 0;
        t = 1; tIns = 0;
        for t in range(1, len(nums)):
            if nums[tIns] != nums[t]:
                nums[tIns+1]=nums[t];
                tIns += 1;
        return tIns+1;

s=Solution();
print s.removeDuplicates([1,1,1,2]);
