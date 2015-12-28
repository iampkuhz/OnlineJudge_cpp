#!/usr/bin/env python
# encoding: utf-8

"""
Implement int sqrt(int x).

Compute and return the square root of x.
"""


class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        def geSqrt(x, a, b):
            if a + 1 >= b:
                return a if b*b > x else b
            m = (a+b)/2
            return geSqrt(x, a, m) if m*m > x else geSqrt(x, m, b)
        return geSqrt(x, 0, x)

s=Solution()
print '1',s.mySqrt(1)
print '16',s.mySqrt(16)
print '10',s.mySqrt(10)
print '0',s.mySqrt(0)


