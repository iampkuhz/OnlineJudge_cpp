#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None: return []
        import Queue
        ls = Queue.Queue()
        ls.put([root,0])
        re = []
        while not ls.empty():
            top = ls.get()
            if top[1] >= len(re): re.append([])
            re[top[1]].append(top[0].val)
            if top[0].left != None: ls.put([top[0].left,top[1]+1])
            if top[0].right != None: ls.put([top[0].right,top[1]+1])
        return re

