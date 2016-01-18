#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    def zigzagLevelOrder(self, root):
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
        return [re[i] if i % 2 == 0 else re[i][::-1] for i in range(len(re)) ]
