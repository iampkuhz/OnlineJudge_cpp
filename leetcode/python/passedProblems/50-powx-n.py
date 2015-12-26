#!/usr/bin/env python
# encoding: utf-8

"""

Implement pow(x, n).

"""


class Solution(object):

    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0:
            return 1 / self.myPow(x, -n)
        if n == 0:
            return 1;
        if n == 1:
            return x
        r = self.myPow(x, n/2)
        if n % 2 == 0:
            return r * r;
        return r * r * x;


s=Solution();
print s.myPow(0.00001, 2147888823);
