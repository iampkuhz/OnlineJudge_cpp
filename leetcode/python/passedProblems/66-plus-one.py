#!/usr/bin/env python
# encoding: utf-8

"""
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
"""

class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        size = len(digits)
        add = 1
        for i in range(size-1, -1, -1):
            sums = add + digits[i]
            digits[i] = sums % 10
            add = sums / 10
        if add == 1:
            digits = [1] + digits
        return digits

