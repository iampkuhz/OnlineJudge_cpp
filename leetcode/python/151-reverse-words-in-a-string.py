#!/usr/bin/env python
# encoding: utf-8

"""
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
"""



# 2次过
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if s == None or len(s) < 1: return s
        wds = s.split(' ')
        wds = [x for x in wds if len(x) > 0]
        wds.reverse()
        return ' '.join(wds)

