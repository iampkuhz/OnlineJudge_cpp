#!/usr/bin/env python
# encoding: utf-8

"""
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
"""

# 11次过，其实不难
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        i, slen = 0, [len(gas)]
        for i in range(slen[0]): gas[i] -= cost[i]
        if slen[0] < 1: return 0
        i = 0
        while True:
            j = (i+1)%slen[0]
            left = gas[i]
            while left >= 0 and j != i:
                left, j = left + gas[j], (j+1) % slen[0]
            if j < i or (j == i and left < 0): return -1
            if j == i: return i
            i = j




# Runtime Error, 原因不明，可能是函数递归太多，去函数
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        i, slen = 0, [len(gas)]
        if slen < 2: return slen-1
        # 循环，找不到，则跳到下一个失败的站点
        def find(left, curS, tarS):
            if left < 0: return curS
            if curS == tarS:
                return tarS
            return find(left + gas[curS] - cost[curS], (curS + 1) % slen[0], tarS)

        while True:
            ni = find(gas[i]-cost[i], (i+1)%slen[0], i)
            print ni
            if ni == i: return i
            if ni < i: return -1
            i = ni


