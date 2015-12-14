#-*-coding:utf-8-*-
"""
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
"""
class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l,r,t=0,len(nums)-1,target;
        while l+1 < r:
            m = (l+r)/2;
            if nums[m] == t:
                return m;
            elif nums[m] > t:
                r = m;
            else:
                l = m+1;
        return l if nums[l] >= t else r if nums[r] >= t else r+1;

s=Solution();
print s.searchInsert([1,3,5,6],5);
print s.searchInsert([1,3,5,6],2);
print s.searchInsert([1,3,5,6],7);
print s.searchInsert([1,3,5,6],0);
print s.searchInsert([1,3,5,6],5);
        
