#!/usr/bin/env python
# encoding: utf-8

"""
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
"""



# 超时
class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        # bfs
        if matrix == None: return 0
        if len(matrix) < 1 or len(matrix[0]) < 1: return 0
        le = [len(matrix), len(matrix[0])]
        lis= [[i,j] for i in range(le[0]) for j in range(le[1])]
        tag = [ [-1 for i in range(le[1])] for j in range(le[0])]
        nlis = []
        def add(a, b, old, dep):
            if a < 0 or a >= le[0] or b < 0 or b >= le[1] or tag[a][b] == dep or matrix[a][b] <= old: return True
            nlis.append([a,b])
            tag[a][b] = dep
            return False
        dep = 0
        while len(lis)>0:
            for p in lis:
                a, b = p[0], p[1]; old = matrix[a][b]
                add(a,b+1, old, dep)
                add(a,b-1, old, dep)
                add(a-1,b, old, dep)
                add(a+1,b, old, dep)
            lis, nlis = nlis, []
            dep += 1
        return dep




