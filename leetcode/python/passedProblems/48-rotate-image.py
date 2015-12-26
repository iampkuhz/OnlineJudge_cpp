#!/usr/bin/env python
# encoding: utf-8

"""
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
"""

class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix[0]);
        for a in range(0,(n+1)/2):
            for b in range(0,(n)/2):
                matrix[b][n-a-1],matrix[n-a-1][n-b-1],matrix[n-b-1][a],matrix[a][b]=matrix[a][b],matrix[b][n-a-1],matrix[n-a-1][n-b-1],matrix[n-b-1][a]

s=Solution();
x=[[1,2],[3,4]]
s.rotate(x);
print x;


