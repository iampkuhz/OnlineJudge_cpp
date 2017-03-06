#!/usr/bin/env python
# encoding: utf-8

"""
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
"""


# 一次过
class Solution(object):
    ac = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n <= 0: return ""
        n -= 1
        return self.convertToTitle(n/26) + self.ac[n % 26]

s=Solution()
print s.convertToTitle(26)
print s.convertToTitle(28)

