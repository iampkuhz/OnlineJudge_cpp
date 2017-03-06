#!/usr/bin/env python
# encoding: utf-8


"""
Given an integer, write a function to determine if it is a power of two.
"""

# 看答案
class Solution(object):
    def isPowerOfTwo(self, n):
        return n > 0 and (n & (n-1)) == 0
class Solution(object):
    def isPowerOfTwo(self, n):
        return n > 0 and (2**31) % n == 0

#循环做，看是否是2的某个幂次
class Solution(object):
    def isPowerOfTwo(self, n):
        x = 1
        for i in range(0, 31):
            if n == x: return True
            x <<= 1
        return False

# 2次过，速度慢
# （错误理解成bit位全1）

class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0: return False
        return (n == 1) or (n%2 == 0 and self.isPowerOfTwo(n/2))


