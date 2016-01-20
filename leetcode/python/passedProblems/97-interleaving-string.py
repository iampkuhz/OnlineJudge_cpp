#!/usr/bin/env python
# encoding: utf-8

"""
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
"""


class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        l1, l2, l3 = len(s1), len(s2), len(s3)
        if l3 != l1 + l2:return False
        itl = [[-1 for i in range(l2+1)] for j in range(l1+1)]
        itl[0][0] = 1
        for i in range(l1+1):
            bk = 0
            for j in range(l2+1):
                if i > 0 and s1[i-1] == s3[i+j-1]:
                    itl[i][j] = max(0, itl[i-1][j])
                if j > 0 and s2[j-1] == s3[i+j-1]:
                    itl[i][j] = max(itl[i][j], itl[i][j-1])
                bk = max(bk, itl[i][j])
            if bk < 1: return False
        return True if itl[l1][l2]>0 else False

