#!/usr/bin/env python
# encoding: utf-8

"""
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
"""


class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if len(grid) == 0 or len(grid[0]) == 0:
            return 0
        re = [[0 for i in range(len(grid[0])+1 )] for j in range(len(grid) + 1)]
        for i in range(1, len(grid) + 1):
            for j in range(1,len(grid[0])+1):
                sum = 0
                if i > 1:
                    sum = re[i-1][j]
                    if j > 1:
                        sum = min(sum, re[i][j-1])
                else:
                    sum = re[i][j-1]
                re[i][j] = grid[i-1][j-1] + sum
        return re[len(grid)][len(grid[0])]

