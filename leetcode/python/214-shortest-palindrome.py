#!/usr/bin/env python
# encoding: utf-8



"""
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
"""


# 4次过， 错在：end-少减1-jp[end-endMatch少-1]
class Solution(object):
    def shortestPalindrome(self, s):
        sl = len(s)
        if sl<2: return s
        # 开头的连续aaaaaa可以在下次计算时跳过
        jp = [0]*sl + [0]
        k = 0
        while k < sl-1 and s[k] == s[k+1]: k += 1
        for i in range(1, sl):
            jp[i] = min(i, k)

        end, endMatch = sl-1, sl-1
        while end > 0:
            while endMatch > end/2 and s[endMatch] == s[end-endMatch]:
                endMatch -= 1
            if endMatch <= end / 2: return s[sl-1:end:-1] + s
            endMatch = end -1 - jp[end-endMatch-1]
            end -= 1
        return s[-1::-1] + s[1:]


# 超时，全部是aaaaa的情况超时
class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        sl = len(s)
        if sl<2: return s

        # 只要找到开头的连续最长回文串就可以了，剩下的补满
        for x in range(len(s)-1, 0,-1):
            if s[0:x/2+1] == s[(x+1)/2:x+1]:
                return s[-1:x:-1] + s
        return s[-1::-1] + s[1:]

