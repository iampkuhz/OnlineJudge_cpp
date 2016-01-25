#!/usr/bin/env python
# encoding: utf-8

"""
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
"""



# 2次过，本地运行3次，时间效率可接受，还有更好的算法
class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        slen = len(s)
        p = [[-1 for i in range(slen)] for j in range(slen)]
        def isP(i, j):
            if i >= j: return True
            #if i == j-1: print s[i:j+1],p[i][j]
            if p[i][j] >= 0: return True if p[i][j] == 1 else False
            p[i][j] = (1 if s[i] == s[j] and isP(i+1,j-1) > 0 else 0)
            return True if p[i][j] == 1 else False

        re = []
        def dfs(ls, ind):
            if ind == slen:
                re.append(ls[:])
                return
            for i in range(ind, slen):
                if isP(ind, i):
                    dfs(ls + [s[ind:i+1]], i+1)
        dfs([], 0)
        return re


s=Solution()
print s.partition("amanaplanacanalpanama")
