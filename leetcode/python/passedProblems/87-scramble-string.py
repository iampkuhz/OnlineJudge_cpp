#!/usr/bin/env python
# encoding: utf-8

"""
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
"""

# 递归超时
class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) != len(s2): return False
        if  s1 == s2: return True
        l1=list(s1); l2=list(s2)
        l1.sort();l2.sort()
        if l1!=l2: return False
        l = len(s1)
        for hf in range(1, l):
            if (self.isScramble(s1[:hf], s2[:hf]) and self.isScramble(s1[hf:], s2[hf:])):
                return True
            if (self.isScramble(s1[:hf], s2[l-hf:]) and self.isScramble(s1[hf:], s2[:l-hf])):
                return True
        return False