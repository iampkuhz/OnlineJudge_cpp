#!/usr/bin/env python
# encoding: utf-8

"""

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

"""

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        re = [0 for i in range(max(10,n+1))]
        re[0], re[1], re[2] = 1, 1, 2
        def findN(nn):
            if re[nn] == 0:
                re[nn] = findN(nn-1) + findN(nn-2)
            return re[nn]
        findN(n)
        return re[n]

