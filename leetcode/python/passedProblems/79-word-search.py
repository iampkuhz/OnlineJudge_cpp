#!/usr/bin/env python
# encoding: utf-8

"""

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
"""


class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        r, c, lw = len(board), len(board[0]), len(word)
        passed = [[False for i in range(c)] for j in range(r)]
        def find(i, j, ind):
            if ind >= lw:
                return True
            if i < 0 or i >= r or j < 0 or j >= c:
                return False
            if (not passed[i][j]) and board[i][j] == word[ind]:
                passed[i][j] = True
                if find(i+1, j, ind+1) or find(i-1, j, ind+1)\
                     or find(i, j + 1, ind+1) or find(i, j-1, ind+1):
                    return True
                passed[i][j] = False

            return False

        for i in range(r):
            for j in range(c):
                if board[i][j] == word[0] and find(i, j, 0):
                    return True
        return False

s=Solution()
#print s.exist([['A','B','C','E'],  ['S','F','C','S'],['A','D','E','E']], 'ABCCED')
#print s.exist([['A','B','C','E'],  ['S','F','C','S'],['A','D','E','E']], 'SEE')
print s.exist([['A','B','C','E'],  ['S','F','C','S'],['A','D','E','E']], 'ABCB')
