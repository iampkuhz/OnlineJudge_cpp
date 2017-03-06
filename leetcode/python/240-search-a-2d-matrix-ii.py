#!/usr/bin/env python
# encoding: utf-8


"""
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.


"""

# 看答案,速度很快
class Solution(object):
    def searchMatrix(self, matrix, target):
        edge = [len(matrix), len(matrix[0])]
        if edge[0] == 0 or edge[1] == 0: return False
        j = edge[1]-1
        for i in range(edge[0]):
            while j >= 0 and matrix[i][j] > target: j -= 1
            if j < 0 : return False
            if matrix[i][j] == target: return True
        return False



# 超时, 不行
class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        edge = [len(matrix), len(matrix[0])]
        visited = [[False]*edge[1] for i in range(edge[0])]
        def find(x,y, target):
            if x >= edge[0] or y >= edge[1] or visited[x][y]: return False
            #if x >= edge[0]: return False
            #if y >= edge[1]: return find(x+1, 0, target)
            v = matrix[x][y]
            visited[x][y] = True
            if v == target: return True
            if v > target:return False
            return find(x+1, y, target) or find(x, y+1, target)
        return find(0,0,target)

