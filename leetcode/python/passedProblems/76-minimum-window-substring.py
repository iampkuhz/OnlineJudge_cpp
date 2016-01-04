#!/usr/bin/env python
# encoding: utf-8

"""

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
"""
# 看答案，双指针
class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        cntS = {}
        for c in t:
            if c not in cntS:
                cntS[c] = 1
            else: cntS[c] += 1
        minStart, minSize, cntN = 1, len(s) + 1, len(t)
        start = 0
        for i in range(len(s)):
            if s[i] in cntS:
                cntS[s[i]] -= 1
                if cntS[s[i]] >= 0:
                    cntN -= 1
            if cntN == 0: # 开始找到了
                while True:
                    if s[start] in cntS:
                        if cntS[s[start]] < 0: # 当前能删
                            cntS[s[start]] += 1
                        else: break # 当前不能删了
                    start += 1 # 当前能删
                if i - start + 1 < minSize:
                    minSize, minStart = i - start + 1, start
        if minSize > len(s):
            return ''
        return s[minStart:minStart+minSize]





s=Solution()
x='axxbaxxcxxdab'
print s.minWindow(x, 'aabcd')
