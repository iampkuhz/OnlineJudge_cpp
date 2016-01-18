#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 算一次过，之前提交的有一个忘删了
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.isV(root)[0]


    def isV(self, node):
        if node == None: return [True, None, None]
        ln = self.isV(node.left)
        rn = self.isV(node.right)
        if (not ln[0]) or (not rn[0]) or (ln[2] != None and ln[2]>=node.val) or (rn[1] != None and rn[1]<=node.val):
            return [False,None,None]
        re=[True]
        re.append(ln[1] if ln[1] != None else node.val)
        re.append(rn[2] if rn[2] != None else node.val)
        return re
