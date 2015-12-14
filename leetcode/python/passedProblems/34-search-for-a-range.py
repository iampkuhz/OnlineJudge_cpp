"""
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
"""
class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        return [self.findMin(nums, 0, len(nums)-1, target), self.findMax(nums, 0, len(nums)-1, target)];
    def findMin(self, ns, a, b, t):
        if a+1 >= b:
            return a if ns[a] == t else b if ns[b] == t else -1;
        m = (a+b)/2;
        if ns[m] >= t:
            return self.findMin(ns, a, m, t);
        return self.findMin(ns, m+1, b, t);

    def findMax(self, ns, a, b, t):
        if a+1 >= b:
            return b if ns[b] == t else a if ns[a] == t else -1;
        m = (a+b)/2;
        if ns[m] <= t:
            return self.findMax(ns, m, b, t);
        return self.findMax(ns, a, m-1, t);

s=Solution();
print s.searchRange([5,7,7,8,8,10],8);
        
