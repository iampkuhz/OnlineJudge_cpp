#!/usr/bin/env python
# encoding: utf-8

"""
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
"""


class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s: return 0
        re = [-1 for i in range(len(s))]
        def dfs(tn):
            if tn < 0:
                return 1 if tn == -1 else 0
            if re[tn] >= 0:
                return re[tn]
            t = 0
            if s[tn] != '0':
                t += dfs(tn-1)
            if tn >= 1 and (s[tn-1] == '1' or (s[tn-1] == '2'  and s[tn] <= '6')):
                t += dfs(tn-2)
            re[tn] = t
            return re[tn]
        return dfs(len(s)-1)

s=Solution()
print s.numDecodings('10')



