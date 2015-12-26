#!/usr/bin/env python
# encoding: utf-8

"""
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
"""

class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        re=[]
        board=[['.' for i in range(n)] for j in range(n)]
        def dup(xi, xj):
            for i in range(n):
                if (board[i][xj] == 'Q' and i != xi) or (board[xi][i] == 'Q' and i != xj):
                    return True;
                j1 = xi + xj - i
                if j1 >= 0 and j1 < n and i != xi and board[i][j1] == 'Q':
                    return True;
                j2 = xj - xi + i;
                if j2 >= 0 and j2 < n  and i != xi and board[i][j2] == 'Q':
                    return True;
            return False;
        def dfs(tn):
            if tn >= n:
                one = []
                for row in board:
                    one.append(''.join(row))
                re.append(one)
                return
            for j in range(n):
                # 检查是否能放
                if(dup(tn,j)):
                    continue
                # 递归
                board[tn][j] = 'Q';
                dfs(tn+1);
                # 还原
                board[tn][j] = '.';
        dfs(0)
        return re;

s=Solution();
print s.solveNQueens(4)
