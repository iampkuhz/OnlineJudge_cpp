#!/usr/bin/env python
# encoding: utf-8

"""

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def bl(node):
            if node == None: return [True, 0]
            lr = bl(node.left)
            rr = bl(node.right)
            if (not lr[0]) or (not rr[0]) or (abs(rr[1]-lr[1])>1):
                return [False, 0]
            return [True, 1+max(lr[1],rr[1])]
        return bl(root)[0]

