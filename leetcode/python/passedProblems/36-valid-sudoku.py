#-*-coding:utf-8-*-
"""
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
"""

class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
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
        for i in range(0,9):
            for j in range(0, 9):
                if board[i][j] == '.':continue;
                tmp = board[i][j];
                board[i][j] = '#';
                if not valid(i,j,tmp):
                    return False;
                board[i][j] = tmp;
        return True;


# 搞错了，不需要判断最后是否有答案，只要看目前已经填充的是否矛盾即可
# 递归填一个，判断横竖方是否满足
#class Solution(object):
#    def isValidSudoku(self, board):
#        """
#        :type board: List[List[str]]
#        :rtype: bool
#        """
#        self.b = board;
#        return self.isV(0,0);
#
#    def isV(self, i, j):
#        if i == 9:
#            return True;
#        if j > 8 :
#            return self.isV(i+1,0);
#        if self.b[i][j] != '.':
#            return self.isV(i,j+1);
#        for v in range(1,10):
#            #self.b[i][j] = str(v)[0];
#            list1 = list(self.b[i]);
#            list1[j] = str(v)[0];
#            self.b[i]= ''.join(list1)
#            dup = False;
#            for k in range(0, 9):
#                if k!=j and self.b[i][k] == self.b[i][j]:
#                    dup = True;break;
#                if k!=i and self.b[k][j] == self.b[i][j]:
#                    dup = True;break;
#            for k1 in range(3*(int)(i/3),3*(int)(i/3)+3):
#                for k2 in range(3*(int)(j/3),3*(int)(j/3)+3):
#                    if not(k1 == i and k2 == j) and self.b[k1][k2] == self.b[i][j]:
#                        dup = True; break;
#            if dup:
#                continue;
#            if self.isV(i,j+1):
#                return True;
#        return False; 

s=Solution();
print s.isValidSudoku(["....2....",".4..9....","...1.....","....4....",".1....69.",".5....7.3","4........","..3......","...4...74"]);
print s.isValidSudoku(["........1",".37...5..",".....6...",".8...9...",".....2..7","...4....5",".........","...93....","..2......"]);
