#!/usr/bin/env python
# encoding: utf-8

"""
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
"""


# 3次过，str（intq[x]), 循环内部每次都要更新intq
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if denominator == 0: return None
        pos = 1
        if numerator < 0: pos = -pos; numerator = -numerator
        if denominator < 0: pos = -pos; denominator = -denominator
        intp = numerator / denominator
        numerator -= intp * denominator
        lev = {}
        intq = []
        i = 0
        while numerator > 0:
            if numerator in lev: break
            lev[numerator] = i
            i += 1
            numerator *= 10
            intq.append(numerator/denominator)
            numerator -= intq[-1] * denominator
            if numerator == 0: break
        if numerator == 0:
            if len(intq) == 0: return ("-" if pos != 1 and intp != 0 else "") + str(intp)
            return ("-" if pos != 1 else "") + str(intp) + "." + "".join(str(x) for x in intq)
        bp = lev[numerator]
        return ("-" if pos != 1 else "") + str(intp) + "." + "".join(str(intq[x]) for x in range(0, bp)) + "(" + "".join(str(intq[x]) for x in range(bp, len(intq))) + ")"
