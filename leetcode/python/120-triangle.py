#!/usr/bin/env python
# encoding: utf-8

"""
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
"""


class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        l = len(triangle)
        if l < 1: return 0
        re = [[0 for i in range(l)] for j in range(2)]
        for i in range(l):
            c = i % 2
            re[c][0] = re[1-c][0] + triangle[i][0]
            for j in range(1, i):
                re[c][j] = min(re[1-c][j],re[1-c][j-1])+triangle[i][j]
            re[c][i] = re[1-c][i-1] + triangle[i][i]
        minre = re[1-l%2][0]
        for i in range(1,l):
            minre = min(minre, re[1-l%2][i])
        return minre

