#!/usr/bin/env python
# encoding: utf-8

"""
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
"""


class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        def getn(x, p):
            re = 0
            while x >= p:
                re, x = re + x/p, x/p
            return re
        return getn(n, 5)

