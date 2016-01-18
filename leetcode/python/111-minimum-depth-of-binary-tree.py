#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        re = [0]
        def fmin(node, d):
            if node == None: return
            if (re[0]>0 and re[0]<=d) or (node.left == None and node.right == None):
                if re[0] <= 0 or d < re[0]:
                    re[0] = d
                return
            fmin(node.left, d+1)
            fmin(node.right, d+1)
        fmin(root, 1)
        return re[0]
