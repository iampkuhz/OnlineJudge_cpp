#!/usr/bin/env python
# encoding: utf-8


"""
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
"""


# 理解错了，是正方形
# 16次过，dp不熟悉

class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        # 每行算连续一的个数，之后每列算连续的最大面积
        r = len(matrix)
        if r == 0: return 0
        c = len(matrix[0])
        if c == 0: return 0
        m1 = [[0]*(1+c) for i in range(r)]
        for j in range(0, c):
            for i in range(0, r):
                m1[i][j] = m1[i-1][j] + 1 if matrix[i][j] == '1' else 0
        re = 0
        for i in range(r):
            asc =[0]
            for j in range(1,c+1):
                while len(asc) > 0 and m1[i][j] <= m1[i][asc[-1]]:
                    wid = j-asc[-2]-1 if len(asc)> 1 else j
                    edge = min(m1[i][asc[-1]], wid)
                    re = max(edge**2, re)
                    asc.pop()
                asc.append(j)
        return re




