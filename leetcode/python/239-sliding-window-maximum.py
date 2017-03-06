#!/usr/bin/env python
# encoding: utf-8



"""
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
"""

# 看答案，速度非常快
# 每次维护当前区间最大值的位置
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        ln = len(nums)
        if ln < 1 or k < 1: return []
        mi, mv = -1,-1
        re = []
        for i in range(ln - k+1):
            if mi < i:
                mi, mv = i, nums[i]
                for j in range(i+1, i+k):
                    if nums[j] > mv:
                        mi, mv = j, nums[j]
            else:
                if mv < nums[i+k-1]:
                    mi, mv = i+k-1, nums[i+k-1]
            re.append(mv)
        return re

# 维护一个k+维的向量，排好序的，每次二分插入一个新的值，看最大值是否在区间内，如果在，则不断弹出
# 速度非常慢，1020ms，可能是每次都一定需要排序
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        ln = len(nums)
        if ln < 1 or k < 1 : return []
        ls = [[nums[i], i] for i in range(0,k)]
        ls.sort(key=lambda x: x[0])
        t = k
        re = [ls[-1][0]]
        def insert(p):
            a, b = 0, len(ls)-1
            while a+1 < b:
                m = (a+b)/2
                if ls[m][0] > p[0]: b = m-1
                elif ls[m][0] < p[0]: a = m+1
                else:
                    ls.insert(m, p)
                    return
            if ls[a][0] > p[0]: ls.insert(a, p)
            elif ls[b][0] > p[0]: ls.insert(b, p)
            else: ls.insert(b+1, p)
        while t < ln:
            insert([nums[t], t])
            while ls[-1][1] < t-k+1: ls.pop()
            re.append(ls[-1][0])
            t += 1
        return re




# 3次之后超时，O(knlogk)的复杂度
class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # 1. 前k个数快排，之后每次加入一个数，看最大值是否在区间内
        ls = [[nums[i], i] for i in range(0, k)]
        ls.sort(cmp=lambda x:x[0])
        re = [ls[-1]]
        ln = len(nums)
        while t < ln:
            ls.append([nums[t],t])
            ls.sort(cmp=lambda x:x[0])
            while ls[-1][1] < t-k+1: ls.pop()
            re.append(ls[-1][0])
            t += 1
        return re





