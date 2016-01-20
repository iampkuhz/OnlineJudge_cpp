#!/usr/bin/env python
# encoding: utf-8

"""

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
"""


# DFS会超内存（Runtime error），采用 BFS
class Solution(object):
    def solve(self, board):
        if len(board) < 1 or len(board[0]) < 1: return
        wd = [len(board), len(board[0])]
        ls = []
        def fill(m,n):
            if m < 0 or m >= wd[0] or n < 0 or n >= wd[1] or board[m][n] != 'O': return
            board[m][n] = 'D'
            ls.append([m,n])

        def fillB(m, n):
            if board[m][n] == 'O': fill(m, n)
            while len(ls)>0:
                tp = ls.pop(0); i=tp[0];j=tp[1]
                fill(i,j+1)
                fill(i,j-1)
                fill(i-1,j)
                fill(i+1,j)
        for i in range(wd[0]):
            fillB(i,0)
            fillB(i,wd[1]-1)
        for j in range(wd[1]):
            fillB(0,j)
            fillB(wd[0]-1,j)
        for i in range(wd[0]):
            for j in range(wd[1]):
                if board[i][j] == 'D': board[i][j] = 'O'
                else: board[i][j] = 'X'






class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        # 从边上的点开始搜O
        if len(board) < 1 or len(board[0]) < 1: return
        wd = [len(board), len(board[0])]
        b2 = [[-1 for i in range(wd[1])] for j in range(wd[0])]
        def fillB(m, n):
            if m < 0 or m >= wd[0] or n < 0 or n >= wd[1] or b2[m][n] > -1: return
            if board[m][n] == 'O':
                b2[m][n] = 1
                fillB(m+1,n)
                fillB(m-1,n)
                fillB(m,n+1)
                fillB(m,n-1)
        for i in range(wd[0]):
            fillB(i,0)
            fillB(i,wd[1]-1)
        for j in range(wd[1]):
            fillB(0,j)
            fillB(wd[0]-1,j)
        for i in range(wd[0]):
            for j in range(wd[1]):
                if b2[i][j] > 0: board[i][j] = 'O'
                else: board[i][j] = 'X'



