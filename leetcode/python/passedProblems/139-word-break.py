#!/usr/bin/env python
# encoding: utf-8

"""

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

"""



# 超时
"""
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
"""
# 4次过，之前剪枝检错了
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: bool
        """
        slen = len(s)
        isW = [[-1 for i in range(slen+1)] for j in range(slen+1)]
        def find(a,b):
            if a > b: return True
            if isW[a][b] >= 0: return True if isW[a][b] > 0 else False
            for i in range(b, a-1, -1):
                if s[a:i+1] in wordDict and find(i+1,b):
                    isW[a][b] = 1
                    return True
            isW[a][b] = 0
            return False
        return find(0, slen-1)

