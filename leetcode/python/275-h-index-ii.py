#!/usr/bin/env python
# encoding: utf-8


"""
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
"""

# 7次过，二分查找
class Solution(object):
    def hIndex(self, citations):
        cl = len(citations)
        if cl <= 0: return 0
        a, b = 0, cl-1
        while a+1 < b:
            m = (a+b)/2
            v = citations[m]
            if v < cl - m -1: a = m+1
            else: b = m
        if citations[a] >= cl - a: return cl - a
        if citations[b] >= cl - b: return cl - b
        return cl - b -1

# 继续超时
class Solution(object):
    def hIndex(self, citations):
        cl = len(citations)
        for i in range(cl-1, -1, -1):
            if citations[i] <= cl-i-1: return cl-i-1
        return cl

# 超时
class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.reverse()
        cl = len(citations)
        for i in range(cl):
            if citations[i] <= i: return i
        return cl

