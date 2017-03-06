#!/usr/bin/env python
# encoding: utf-8


"""
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
"""

# 看答案，7次过
class Solution(object):
    def maxProfit(self, prices):
        pl = len(prices)
        if pl < 2: return 0
        hold, noHold, noHold_cool = -2**31, 0, -2**31
        for p in prices:
            hold, noHold, noHold_cool = max(hold, noHold - p), max(noHold, noHold_cool), hold+p
        return max(noHold_cool, noHold)


# DP, O(n^2)，超时
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # DP, O(n^2)
        pl = len(prices)
        if pl < 2: return 0
        re = [0] * (pl+3)
        re[1] = max(0, prices[1] - prices[0])
        for i in range(2, pl):
            re[i] = max(0, re[i-1])
            for j in range(0, i):
                if prices[i] > prices[j]:
                    re[i] = max(prices[i] - prices[j] + re[j-2], re[i])
        return max(re)



