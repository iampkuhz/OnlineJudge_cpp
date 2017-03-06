#!/usr/bin/env python
# encoding: utf-8


"""
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
"""


# 看答案
class Solution(object):
    def addDigits(self, num):
        if num <= 0: return 0
        if num % 9 == 0: return 9
        return num % 9

# 1次过
class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num < 10: return num
        return self.addDigits(sum([int(t) for t in str(num)]))

