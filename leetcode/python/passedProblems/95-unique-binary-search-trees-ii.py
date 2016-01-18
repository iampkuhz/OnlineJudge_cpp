#!/usr/bin/env python
# encoding: utf-8


"""
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 提交14次，各种细节没有考虑到
class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n = 0: return None
        def dfs(tn, base):
            if n == 0 : return [None]
            if n == 1 : return [ListNode(1+base)]
            re = []
            for i in range(1, tn+1):
                lf = dfs(i-1, 0)
                rt = dfs(tn-i, i)
                for j in (lf):
                    for k in (rt):
                        root = TreeNode(i)
                        root.left, root.right = j, k
                        re.append(re)
            return re
        return dfs(n,0)



