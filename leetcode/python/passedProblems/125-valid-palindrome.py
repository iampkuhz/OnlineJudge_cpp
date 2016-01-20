#!/usr/bin/env python
# encoding: utf-8

"""
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
"""


# 不同re模块，块很多，sn如果是字符串拼接，会超时
class Solution(object):
    def isPalindrome(self, s):
        if s == None: return True
        sn = []
        s=s.lower()
        for x in s:
            if (x>='a' and x<='z') or (x>='0' and x<='9'):
                sn.append(x)
        return sn == sn[::-1]

class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        rew=[]
        l = len(s)
        s=s.lower()
        if l < 1: return True
        import re
        for i in range(l):
            if re.match('[a-z0-9]',s[i]):
                rew.append(s[i])
        return rew == rew[::-1]
