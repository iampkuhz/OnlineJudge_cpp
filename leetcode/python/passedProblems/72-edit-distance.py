#!/usr/bin/env python
# encoding: utf-8

"""
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
"""



class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        if len(word1) < len(word2):
            return self.minDistance(word2, word1)
        if len(word2) == 0:
            return len(word1)
        re = [[i for i in range(len(word2)+1)] for i in range(2)]
        for ii in range(1, len(word1)+1):
            re[ii%2][0] = ii
            for j in range(1, len(word2)+1):
                i = ii % 2
                if word1[ii-1] == word2[j-1]:
                    re[i][j] = re[1-i][j-1]
                else:
                    re[i][j] = min(min(re[1-i][j], re[i][j-1]), re[1-i][j-1]) + 1
        return re[len(word1)%2][len(word2)]

s=Solution()
print s.minDistance("ab","bc")
print s.minDistance("sea","ate")

