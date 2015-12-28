#!/usr/bin/env python
# encoding: utf-8

"""
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
"""


class Solution(object):
    def lengthOfLastWord(self, s):
        return len(s.split()[-1]) if s.split() != [] else 0

#class Solution(object):
#    def lengthOfLastWord(self, s):
#        """
#        :type s: str
#        :rtype: int
#        """
#        if(len(s) < 1):
#            return 0
#        re = 0
#        lastEm = -1
#        for i in range(len(s)):
#            if s[i] == ' ':
#                re = i - lastEm - 1 if i > lastEm+1 else re
#                lastEm = i
#        if s[-1] != ' ':
#            re = len(s) - lastEm - 1
#        return re

s=Solution()
print s.lengthOfLastWord("Hello World")


