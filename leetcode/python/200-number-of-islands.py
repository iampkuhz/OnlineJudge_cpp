#!/usr/bin/env python
# encoding: utf-8

"""
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
"""

# fenxi:深搜容易实现，可能超时？用宽搜试试
# 2次过：Add（ti，tj-1），不是Add（i，j-1）

class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if len(grid) < 1 or len(grid[0]) < 1: return 0
        l = [len(grid), len(grid[0])]
        ls = []
        re = [0]

        def Add(i, j):
            if i < 0 or i >= l[0] or j < 0 or j >= l[1] or grid[i][j] != '1': return
            grid[i][j] = 'x'
            ls.append((i,j))

        def bfs(i, j):
            if grid[i][j] == '1':
                re[0] += 1
                ls.append((i,j))
                while len(ls) > 0:
                    ti, tj = ls.pop(0)
                    Add(ti+1, tj)
                    Add(ti-1, tj)
                    Add(ti, tj+1)
                    Add(ti, tj-1)
        for i in range(0, l[0]):
            for j in range(0, l[1]):
                bfs(i,j)
        return re[0]
