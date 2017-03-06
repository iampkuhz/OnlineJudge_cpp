#!/usr/bin/env python
# encoding: utf-8


"""
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.


"""


# 1次过，感觉速度还需要提升
class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num < 1: return False
        while num &1 == 0: num >>= 1
        while num % 5 == 0: num /= 5
        while num % 3 == 0: num /= 3
        return num == 1

