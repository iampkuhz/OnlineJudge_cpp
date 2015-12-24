"""
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
"""

class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        def valid(x, y, tmp):
            for i in range(0,9):
                if board[i][y] == tmp or board[x][i] == tmp:
                    return False;
            b1,b2 = (int)(x/3), (int)(y/3);
            for k1 in range(3*b1, 3*b1+3):
                for k2 in range(3*b2, 3*b2+3):
                    if board[k1][k2] == tmp: return False;
            return True;
        
        def dfs():
            for i in range(0,9):
                for j in range(0,9):
                    if board[i][j] == '.':
                        for k in '123456789':
                            if valid(i,j, k):
                                board[i][j] = k;
                                if( dfs()): return True;
                        return False;
            return True;
        dfs();

s=Solution();
s.solveSudoku(["....2....",".4..9....","...1.....","....4....",".1....69.",".5....7.3","4........","..3......","...4...74"]);
#s.solveSudoku(["........1",".37...5..",".....6...",".8...9...",".....2..7","...4....5",".........","...93....","..2......"]);
        
