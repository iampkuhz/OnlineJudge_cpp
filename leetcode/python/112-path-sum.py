#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root == None: return False
        def find(root1,sum1):
            if root1 == None: return False
            s = sum1-root1.val
            if root1.left == None and root1.right == None: return False if s != 0 else True
            return find(root1.left, sum1-root1.val) or find(root1.right, sum1-root1.val)
        return find(root, sum)
