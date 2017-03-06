#!/usr/bin/env python
# encoding: utf-8

"""
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
"""


# 2次过，return是二维数组，不是一维数组
# python可以判断二维int数组只是否相等
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        def lcmp(l1, l2):
            return 1 if l1[0] > l2[0] else -1
        def s2l(str):
            dic = {}
            for i in range(len(str)):
                c = str[i]
                if c not in dic:
                    dic[c] = []
                dic[c].append(i)
            ls = []
            for x in dic:
                ls.append(dic[x])
            ls.sort(lcmp)
            return ls
        return s2l(s) == s2l(t)

