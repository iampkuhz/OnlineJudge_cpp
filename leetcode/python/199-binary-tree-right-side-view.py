#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# 2次过，append(left pair)
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ls = [(root, 1)]
        if root == None: return []
        re = []
        while len(ls) > 0:
            tp, lv = ls.pop(0)
            if lv > len(re): re.append(tp.val)
            else: re[lv-1] = tp.val
            if tp.left != None: ls.append((tp.left,lv+1))
            if tp.right != None: ls.append((tp.right, lv+1))
        return re
