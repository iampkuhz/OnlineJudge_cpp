#!/usr/bin/env python
# encoding: utf-8


"""

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
"""

# 2次过，速度慢
class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 1: return 1
        bkt = [[2],[3],[5]]
        a = [2,3,5]
        last = 1
        while n > 1:
            for i in range(0,3):
                while bkt[i][0] <= last: bkt[i].pop(0)
            mi, mv = 0, bkt[0][0]
            for i in range(1,3):
                if bkt[i][0] < mv:
                    mi, mv = i, bkt[i][0]
            last = mv
            bkt[mi].pop(0)
            for i in range(0,3):
                bkt[i].append(last * a[i])
            n -= 1
        return last



