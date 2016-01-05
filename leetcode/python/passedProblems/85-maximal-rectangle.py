#!/usr/bin/env python
# encoding: utf-8

"""
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
"""


class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        # 基于84题柱状图中的最大长方形思路
        if (not matrix) or not matrix[0]: return 0
        r, c = len(matrix), len(matrix[0])
        sq = [[ 0 for i in range(c+1)] for j in range(r+1)]
        for i in range(r):
            for j in range(c):
                sq[i][j] = 0 if matrix[i][j] == '0' else sq[i][j-1] + 1
        re = 0
        for j in range(c):
            stk = []
            for i in range(r+1):
                while (stk and sq[i][j] <= sq[stk[-1]][j]):
                    re = max(re, sq[stk.pop()][j] * (i if not stk else i-stk[-1]-1))
                stk.append(i)
        return re
