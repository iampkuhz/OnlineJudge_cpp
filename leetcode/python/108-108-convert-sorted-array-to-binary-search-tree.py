#!/usr/bin/env python
# encoding: utf-8

"""
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 两次过，忘写return了
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def st(a,b):
            if a>b:return None
            m = (a + b) / 2
            root = TreeNode(nums[m])
            root.left = st(a, m-1)
            root.right = st(m+1, b)
            return root
        return st(0, len(nums)-1)

