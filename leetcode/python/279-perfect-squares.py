#!/usr/bin/env python
# encoding: utf-8


"""
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
"""

# DP需要动态申请内存，复用之前的结果，非常重要！！！
class Solution(object):
    _cnt = [0]
    def numSquares(self, n):
        cnt = self._cnt
        if n >= len(cnt):
            for i in range(len(cnt), n+1):
                cnt.append(min(cnt[-t*t] for t in range(1, int(math.sqrt(i))+1)) + 1)
        return cnt[n]

# 四平方和定理
class Solution(object):
    def numSquares(self, n):
        while n % 4 == 0: n /= 4
        if n % 8 == 7: return 4
        b = int(math.sqrt(n))
        if b * b == n: return 1
        for i in range(1,b+1):
            a = int(math.sqrt(n - i*i))
            if n == a*a + i * i: return 2
        return 3

# 超时:5156
class Solution(object):
    def numSquares(self, n):
        cnt = [0]* (n+1)
        def find(x):
            if x < 1:return 0
            if cnt[x] > 0: return cnt[x]
            k = int(math.sqrt(x))
            re = x
            for j in range(2, k+1):
                re = min(re, find(x-j*j) + 1)
            cnt[x] = re
            return cnt[x]
        return find(n)

# 超时：6225
class Solution(object):
    def numSquares(self, n):
        cnt = [0] * (n+1)
        for i in range(1, n+1):
            k = math.sqrt(i)
            re = i
            for j in range(2, k+1):
                re = min(re, cnt[i-j*j] + 1)
            cnt[i] = re
        return cnt[n]

# 超时：5778
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = [0] * (n+1)
        def find(x, thr):
            if x <= 3 or thr < 1: return x
            if cnt[x] > 0: return cnt[x]
            re = x-1
            for t in range(int(math.sqrt(x)), 1, -1):
                re = min(find(x-t*t, min(re, thr-1)), re)
            cnt[x] = re + 1
            #print x,cnt[x]
            return cnt[x]

        return find(n, n)





