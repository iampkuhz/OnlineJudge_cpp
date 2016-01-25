#!/usr/bin/env python
# encoding: utf-8

"""
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
"""


# find最后忘记return，debug好长时间，12次过
class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: Set[str]
        :rtype: List[str]
        """
        slen = len(s)
        isW = [[-1 for i in range(slen)] for j in range(slen)]
        def find(a, b):
            if a > b: return [[]]
            if isW[a][b] != -1: return isW[a][b]
            tmp = []
            for i in range(a,b+1):
                tw = s[a:i+1]
                if tw in wordDict:
                    ttmp = find(i+1,b)
                    if ttmp != None:
                        for x in ttmp:
                            tmp.append([tw] + x)
            isW[a][b] = tmp[:] if len(tmp) > 0 else None
            return isW[a][b]
        re = find(0, slen-1)
        if re == None: return []
        return [" ".join(x) for x in re]




