#!/usr/bin/env python
# encoding: utf-8

"""

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
"""


class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        re = [[0 for i in range(n)] for j in range(n)]
        sind = 1
        for k in range(n/2):
            for i in range(k, n-k-1):
                re[k][i] = sind; sind += 1
            for j in range(k, n-k-1):
                re[j][n-k-1] = sind; sind += 1
            for i in range(n-k-1, k, -1):
                re[n-k-1][i] = sind; sind += 1
            for j in range(n-k-1, k, -1):
                re[j][k] = sind; sind += 1
        if n % 2 == 1:
            re[n/2][n/2] = sind
        return re

s=Solution()
print s.generateMatrix(3)
print s.generateMatrix(4)


