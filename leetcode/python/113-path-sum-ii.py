#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        ls = []
        re = []
        def find(node, s):
            if node == None:return
            ls.append(node.val)
            lf = s - node.val
            if node.left == None and node.right == None:
                if lf == 0: re.append(ls[:])
            find(node.left, lf)
            find(node.right, lf)
            ls.pop()

        find(root,sum)
        return re


