#!/usr/bin/env python
# encoding: utf-8

"""
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
"""

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if len(matrix) == 0:
            return []
        x1, x2, y1, y2 = 0, len(matrix)-1, 0, len(matrix[0])-1
        re = []
        while x1 < x2 and y1 < y2:
            for j in range(y1, y2):
                re.append(matrix[x1][j])
            for i in range(x1, x2):
                re.append(matrix[i][y2])
            for j in range(y2, y1, -1):
                re.append(matrix[x2][j])
            for i in range(x2, x1, -1):
                re.append(matrix[i][y1])
            x1, x2, y1, y2 = x1+1, x2-1, y1+1, y2-1;
        if x1 == x2:
            for j in range(y1, y2+1):
                re.append(matrix[x1][j])
        elif y1 == y2:
            for i in range(x1, x2+1):
                re.append(matrix[i][y1])
        return re

s=Solution()
print s.spiralOrder([[1,2,3],[4,5,6],[7,8,9]])

