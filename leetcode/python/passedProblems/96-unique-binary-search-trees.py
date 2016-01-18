#!/usr/bin/env python
# encoding: utf-8


"""
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""

# leetcode 参考答案,一次过，速度没有优势
class Solution(object):
    def numTrees(self, n):
        re = [1]
        for i in range(1,n+1):
            re.append(sum(map(lambda x,y:x*y, re, reversed(re))))
        return re[n]



# 3次过，第一次递归超时，第二次调用函数错写成`dfs[n]`
class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        re = [1,1,2] + [-1 for i in range(n)]
        def dfs(tn):
            if re[tn] >= 0 : return re[tn]
            r = 0
            for i in range(1, tn+1):
                r += dfs(i-1) * dfs(tn-i)
            re[tn] = r
            return re[tn]
        return dfs[n]
