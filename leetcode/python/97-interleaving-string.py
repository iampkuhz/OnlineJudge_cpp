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


        def dfs(tl3):
            for tl1 in range(max(0, tl3-l2), min(l1+1,  tl3+1)):
                tl2 = tl3-tl1
                if itl[tl1][tl2]>=0:return True if itl[tl1][tl2] == 1 else False
                re = 0
                if tl1 > 0 and s1[tl1-1] == s3[tl3-1]:
                    re = itl[tl1-1][tl2]
                if tl2 > 0 and s2[tl2-1] == s3[tl3-1]:
                    re = max(re, itl[tl1][tl2-1])
                itl[tl1][tl2] = re
                if( re > 0): return True
            return False
        return dfs(l3)
