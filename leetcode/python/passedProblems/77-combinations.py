#!/usr/bin/env python
# encoding: utf-8

"""
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
"""


class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        re, tlist = [], []
        def find(tn):
            if len(tlist) == k:
                re.append(tlist[:])
                return
            if tn > n or n - tn + 1 < k - len(tlist):
                return
            tlist.append(tn)
            find(tn+1)
            tlist.pop()
            find(tn+1)
        find(1)
        return re


s=Solution()
print s.combine(4,2)
