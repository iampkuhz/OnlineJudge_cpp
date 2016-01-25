#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 两次过，简单，貌似有更好方法
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        re = [0]
        def dfs(node, fsum):
            if node == None: return
            fsum = fsum * 10 + node.val
            if node.left == None and node.right == None:
                re[0] += fsum
                return
            dfs(node.left, fsum)
            dfs(node.right, fsum)
        dfs(root, 0)
        return re[0]


