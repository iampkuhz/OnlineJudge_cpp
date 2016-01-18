#!/usr/bin/env python
# encoding: utf-8

"""
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
"""



class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        ls, lt = len(s), len(t)
        re = [[1] + [0 for i in range(lt)] for j in range(2)]
        re[0][0] = 1
        for i in range(0, ls):
            for j in range(0, lt):
                r = i%2
                if s[i] == t[j]:
                    re[r][j+1] = re[1-r][j] + re[1-r][j+1]
                else: re[r][j+1] = re[1-r][j+1]
        return re[(ls+1)%2][lt]
