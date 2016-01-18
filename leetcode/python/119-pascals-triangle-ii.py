#!/usr/bin/env python
# encoding: utf-8

"""
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
Note:
Could you optimize your algorithm to use only O(k) extra space?
"""



class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex < 2: return [1]*(rowIndex+1)
        re = [[1]+[0]*(rowIndex), [1,1]+[0]*(rowIndex-1)]
        for i in range(2,rowIndex+1):
            c = i%2
            re[c] = [1] + [re[1-c][l]+re[1-c][l+1] for l in range(i-1)] + [1]
        return re[rowIndex%2]
