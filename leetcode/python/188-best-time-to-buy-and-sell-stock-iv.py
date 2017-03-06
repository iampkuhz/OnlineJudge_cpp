#!/usr/bin/env python
# encoding: utf-8



"""
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

"""


# 超时
class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        plen = len(prices)
        mp = [[0] * (1+plen) for i in range(k+1)]
        for times in range(1, 1+k):
            for j in range(1, plen):
                mx = mp[times-1][j]
                for i in range(0, j):
                    if prices[i] < prices[j]:
                        mx = max(mp[times-1][i-1]+ prices[j]-prices[i], mx)
                mp[times][j] = max(mx, mp[times][j-1])
        return mp[k][plen-1]


