#!/usr/bin/env python
# encoding: utf-8


"""
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
"""


# 4次过，sum剪枝的时候写错了
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        re = []; ls = []
        def fd(kk, nn, tn):
            if nn <= 0 or kk <= 0:
                if nn == 0 and kk == 0: re.append(ls[:])
                return
            if 10-tn < kk or  sum([x for x in range(10-kk, 10) if x >=tn]) < nn: return
            fd(kk, nn, tn+1)
            ls.append(tn)
            fd(kk-1, nn-tn,tn+1)
            ls.pop()
        fd(k, n, 1)
        return re
