#!/usr/bin/env python
# encoding: utf-8

"""
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
"""


class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if numRows <=  0 : return []
        re = [[1]]
        for i in range(1, numRows):
            re.append([1] + [re[i-1][l+1]+re[i-1][l] for l in range(i-1)] + [1])
        return re



