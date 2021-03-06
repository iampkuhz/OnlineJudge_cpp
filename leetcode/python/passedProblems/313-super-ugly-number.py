#!/usr/bin/env python
# encoding: utf-8

"""
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
"""



# 看答案， 516ms
class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        lp = len(primes)
        vlt = [1 for i in range(lp)]
        ilt = [-1 for i in range(lp)]
        ug = [1 for i in range(n)]
        k = 0
        while k < n:
            x = min(vlt)
            ug[k] = x
            k += 1
            for v in range(lp):
                if x == vlt[v]:
                    ilt[v] += 1
                    vlt[v] = ug[ilt[v]] * primes[v]
        return ug[n-1]

# 超时
class Solution(object):
    def nthSuperUglyNumber(self, n, primes):
        """
        :type n: int
        :type primes: List[int]
        :rtype: int
        """
        pb = [[primes[i]] for i in range(len(primes))]
        if n == 1: return 1
        mi = pb[0][0]
        while n > 0:
            mi = pb[0][0]
            n -= 1; ind = 0
            for j in range(1, len(primes)):
                if pb[j][0] < mi[1]:
                    mi = pb[j][0]; ind = j
            for i in range(len(primes)):
                pb[i].append(primes[i] * mi)
            pb[ind].pop(0)
        return mi

