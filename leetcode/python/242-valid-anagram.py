#!/usr/bin/env python
# encoding: utf-8


"""
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
"""


# 2次过
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # 判断字符串是否含有相同的字符
        def cnt(st):
            re = [0] * 26
            for x in st:
                re[ord(x)-ord('a')] += 1
            return re
        return cnt(s) == cnt(t)

