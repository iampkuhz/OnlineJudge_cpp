#!/usr/bin/env python
# encoding: utf-8


"""
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 判断None：x ！= None，不能用`not x`
# 判断Queue empty：not x.empty()
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if None == root: return []
        import Queue
        ls = Queue.Queue()
        ls.put([root,0])
        re = []
        while not ls.empty():
            tp = ls.get()
            if tp[1] >= len(re): re.append([tp[0].val])
            else: re[tp[1]].append(tp[0].val)
            if None != tp[0].left: ls.put([tp[0].left, tp[1]+1])
            if None != tp[0].right: ls.put([tp[0].right, tp[1]+1])
        re.reverse()
        return re

