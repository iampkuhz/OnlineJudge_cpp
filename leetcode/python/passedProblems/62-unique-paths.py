#!/usr/bin/env python
# encoding: utf-8

"""
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.


"""


class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        re = [[1 for i in range(n)] for j in range(m)]
        re[0][0] = 1
        for i in range(1, m):
            for j in range(1, n):
                re[i][j] = re[i-1][j] + re[i][j-1]
        return re[m-1][n-1]

