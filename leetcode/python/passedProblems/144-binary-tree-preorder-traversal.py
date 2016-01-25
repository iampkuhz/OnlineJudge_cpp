#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# iter,看答案,2次过，第一次对齐错误
class Solution(object):
    def preorderTraversal(self, root):
        ans, nds = [], [root]
        while len(nds) > 0:
            nd = nds.pop()
            while nd:
                if nd.right != None: nds.append(nd.right)
                ans.append(nd.val)
                nd = nd.left
        return ans


# 一次过，简单,dfs
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        re = []
        def dfs(node):
            if node == None: return
            re.append(node.val)
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return re

