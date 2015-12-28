#!/usr/bin/env python
# encoding: utf-8

"""
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
"""


class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        if len(obstacleGrid) == 0 or len(obstacleGrid[0]) == 0:
            return 0
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        re = [[0 for i in range(n+1)] for j in range(m+1)]
        re[0][1] = 1
        for i in range(1, m+1):
            for j in range(1, n+1):
                if obstacleGrid[i-1][j-1] != 1:
                    re[i][j] = re[i-1][j] + re[i][j-1]
        return re[m][n]


