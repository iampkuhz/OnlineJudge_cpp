#!/usr/bin/env python
# encoding: utf-8


"""
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up:
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

"""

# 9次过，速度慢
class Solution(object):
    def gameOfLife(self, board):
        """
        :type board: List[List[int]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        b2 = [row[:] for row in board]
        edge = [len(board), len(board[0])]
        def acti(a,b):
            if a < 0 or a >= edge[0] or b <0 or b >= edge[1] or b2[a][b] == 0: return 0
            return 1
        def nstat(a,b):
            cnt = 0
            for i in range(a-1, a+2):
                for j in range(b-1, b+2):
                    cnt += acti(i,j)
            cnt -= acti(a,b)
            if acti(a,b) > 0 and cnt > 1 and cnt <=3: return 1
            if acti(a,b) == 0 and cnt == 3: return 1
            return 0

        for i in range(edge[0]):
            for j in range(edge[1]):
                board[i][j] = nstat(i,j)


