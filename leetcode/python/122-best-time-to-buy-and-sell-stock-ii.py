#!/usr/bin/env python
# encoding: utf-8

"""
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
"""


# 贪心，连续的上升序列
class Solution(object):
    def maxProfit(self, prices):
        l = len(prices)
        if l == 0: return 0
        us, ue = prices[0],prices[0]
        re = 0
        for i in range(1, l):
            if prices[i] >= ue:
                ue = prices[i]
            else:
                re += ue - us
                us = ue = prices[i]
        re += ue - us
        return re


# 超时
class Solution(object):
    def maxProfit(self, prices):
        l = len(prices)
        re = [0,0]
        for i in range(1, l):
            re.append(re[-1])
            for j in range(0,i):
                if prices[j] < prices[i]:
                    re[-1] = max(re[-1], re[j]+prices[i]-prices[j])
        return re[-1]

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        # 错误：同一天只能卖一个：找每天之后的最大值，如果比今天大，则在今天买的在之后的最大值天卖掉
        l = len(prices)
        maxAf = prices[-1]
        re = 0
        for i in range(l-2, -1, -1):
            maxAf = max(maxAf, prices[i])
            re += maxAf - prices[i]
        return re



