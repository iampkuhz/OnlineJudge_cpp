#!/usr/bin/env python
# encoding: utf-8

"""


Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

"""

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices: return 0
        re = 0; ma, mi = prices[0],prices[0]
        for i in range(1, len(prices)):
            re = max(re, prices[i]-mi)
            mi = min(mi, prices[i])
        return re
