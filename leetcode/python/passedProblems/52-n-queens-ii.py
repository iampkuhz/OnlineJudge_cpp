#!/usr/bin/env python
# encoding: utf-8

"""
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
"""

# 快速算法
class Solution(object):
    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        re = [0]

        def dfs(nn, lineQ, ls, rl):
            if nn >= n:
                re[0] += 1; return
            for j in range(n):
                if j not in lineQ and (nn-j not in ls) and (nn+j not in rl):
                    dfs(nn+1, lineQ + [j], ls + [nn-j], rl + [nn+j])

        dfs(0, [], [], [])
        return re[0]

# 一维数组存放每行皇后的位置
#class Solution(object):
#    def totalNQueens(self, n):
#        """
#        :type n: int
#        :rtype: int
#        """
#        lineQ=[-1 for i in range(n)]
#
#        def access(xi, xj):
#            for i in range(xi):
#                if abs(lineQ[i] - xj) == 0 or abs(i - xi) == abs(lineQ[i]- xj):
#                    return False
#            return True
#
#        re = [0]
#
#        def dfs(nn):
#            if nn >= n:
#                re[0] += 1; return
#            for j in range(n):
#                if access(nn, j):
#                    lineQ[nn] = j
#                    dfs(nn + 1)
#        dfs(0)
#        return re[0]

s=Solution()
print s.totalNQueens(4)



