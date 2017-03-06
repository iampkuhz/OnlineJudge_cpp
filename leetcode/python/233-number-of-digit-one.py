#!/usr/bin/env python
# encoding: utf-8


"""
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
"""


# 13次过，递归没有考虑请
class Solution(object):
    def countDigitOne(self, n):
        """
        :type n: int
        :rtype: int
        """
        # dn[i]表示所有i位数字含有的1个数
        # re[i]表示n的后i位数字含有的1个数
        if n <= 0: return 0
        rn = (str(n))[-1::-1]
        nl = len(rn)
        dn, re, p10, leftn = [0]*nl, [0]*nl, 1, 0
        for i in range(nl):
            t = int(rn[i])
            if t > 1:
                re[i] = re[i-1] + p10 + t * dn[i-1]
            elif t == 1:
                re[i] = re[i-1] + (leftn+1) + dn[i-1]
            else: re[i] = re[i-1]
            dn[i] = dn[i-1] * 10 + p10
            leftn, p10 = leftn + t * p10, p10 * 10
        return re[-1]

