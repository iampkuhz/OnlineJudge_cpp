#!/usr/bin/env python
# encoding: utf-8

"""

Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
"""


# 一次过
class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0: return 0
        return self.titleToNumber(s[0:-1]) * 26 + (ord(s[-1]) - ord('A') + 1)


