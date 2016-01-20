#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        re = [None]
        def find(node):
            if node == None: return 0
            lmx = find(node.left)
            rmx = find(node.right)
            tmax = (node.val)
            if lmx > 0: tmax += lmx
            if rmx > 0: tmax += rmx
            re[0] = tmax if (re[0] == None or tmax > re[0]) else re[0]
            return node.val + max(0,max(lmx, rmx))
        find(root)
        return re[0]


