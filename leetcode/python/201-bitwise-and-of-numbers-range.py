#!/usr/bin/env python
# encoding: utf-8


"""
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
"""


# 4次过，2^i是位异或，2**i是幂
class Solution(object):
    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        i = 0
        while m < n:
            i, m, n = i + 1, m/2, n/2
        return m * (2**i)



