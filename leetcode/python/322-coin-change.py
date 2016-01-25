#!/usr/bin/env python
# encoding: utf-8

"""
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
"""


class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        cnt = [-1 for i in range(amount + 1)]
        coins.sort().reverse()
        def find(mt):
            if mt < 0: return 0
            if mt == 0: return 1
            if cnt[mt] >= 0 : return cnt[mt]
            re = 0
            for c in coins:
                t = find(mt - c)
                if t > 0:
                    cnt[mt] = t + 1
                    return t + 1
            cnt[mt] = 0
            return re
        return find(amount)

