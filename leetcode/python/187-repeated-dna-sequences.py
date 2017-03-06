#!/usr/bin/env python
# encoding: utf-8

"""
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
"""



# 2次过，-9，,10搞混了
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        wf = {}
        for i in range(0, len(s)-9):
            ss = s[i:i+10]
            wf[ss] = wf.get(ss, 0) + 1
        re = []
        for i in wf:
            if wf[i] > 1:
                re.append(i)
        return re


