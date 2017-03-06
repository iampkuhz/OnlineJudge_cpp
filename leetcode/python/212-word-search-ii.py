#!/usr/bin/env python
# encoding: utf-8



"""
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
"""



# 看题意是想让我们用字典树：a-z
# 用带查找的word制作字典，查询board上面的序列是否在字典中，从board上每个点向下找

# 26次过
class TrieNode(object):
    def __init__(self):
        self.char = None
        self.end = False
        self.child = {}
class Solution(object):
    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        self.r, self.c = len(board), len(board[0])
        if self.r == 0 or self.c == 0: return []
        self.root = TrieNode()
        self.re = set()
        self.board = board
        for wd in words:
            self.insert(wd)
        for i in range(self.r):
            for j in range(self.c):
                self.visit = set()
                self.route = []
                self.search(self.root, i,j)
        return list(self.re)

    def insert(self, word):
        t = self.root
        for x in word:
            if x not in t.child:
                t.child[x] = TrieNode()
                t = t.child[x]
                t.char = x
            else: t = t.child[x]
        t.end = True

    def search(self, node, a,b):
        #if a<0 or a >= self.r or b < 0 or b >= self.c or ((a,b) in self.visit) or  self.board[a][b] not in node.child: return
        if a<0 or a >= self.r or b < 0 or b >= self.c or ((a,b) in self.visit): return
        c = self.board[a][b]
        if len(node.child) < 1:
            self.re.add("".join(self.route))
            return
        if  self.board[a][b] not in node.child: return
        self.route.append(c)
        nn = node.child[c]
        self.visit.add((a,b))
        self.search(nn, a+1, b)
        self.search(nn, a-1, b)
        self.search(nn, a, b+1)
        self.search(nn, a, b-1)
        self.visit.remove((a,b))
        self.route.pop()



