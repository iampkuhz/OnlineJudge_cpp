#!/usr/bin/env python
# encoding: utf-8

"""

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

"""


# 考虑边界，两次过
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 前后两个方向计算最大值，结果相加
        l = len(prices)
        if l < 1: return
        lr = [0]
        lmin = prices[0]
        for i in range(1,l):
            lmin = min(lmin, prices[i])
            lr.append(max(lr[-1],prices[i]-lmin))
        rl = [0]
        rmax = prices[-1]
        for i in range(l-2, -1, -1):
            rmax = max(rmax, prices[i])
            rl.append(max(rl[-1],rmax-prices[i]))
        rl.reverse()
        re = rl[0]
        for i in range(1, l):
            re = max(re, lr[i-1]+ rl[i])
        return re


