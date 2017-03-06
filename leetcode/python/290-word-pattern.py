#!/usr/bin/env python
# encoding: utf-8


"""


Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.


"""

# 7次过
class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        wds = str.split(' ')
        if len(wds) != len(pattern): return False
        chr2str = {}
        p = []
        for i in range(len(wds)):
            p.append([wds[i], ord(pattern[i])])
        p.sort(key = lambda x:x[1])
        for i in range(0, len(p)-1):
            if p[i][1] == p[i+1][1] and p[i][0] != p[i+1][0]:
                return False
            if p[i][1] != p[i+1][1] and p[i][0] == p[i+1][0]:
                return False
        return True

