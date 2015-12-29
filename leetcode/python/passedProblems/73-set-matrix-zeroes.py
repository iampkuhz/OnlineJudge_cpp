#!/usr/bin/env python
# encoding: utf-8

"""
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
"""


class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        l = [0 for _ in range(len(matrix))]
        r = [0 for _ in range(len(matrix[0]))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    l[i] = r[j] = 1
        for i in range(len(l)):
            if l[i] == 1:
                for j in range(len(r)):
                    matrix[i][j] = 0
        for j in range(len(r)):
            if r[j] == 1:
                for i in range(len(l)):
                    matrix[i][j] = 0


