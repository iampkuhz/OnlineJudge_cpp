#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
"""

# 看答案，用BFS实现,7次过，None的判断老出问题，92ms->70ms

class Solution(object):
    def minDepth(self, root):
        ls = collections.deque([(root,1)])
        if not root: return 0
        while ls:
            node,dep = ls.popleft()
            if (not node.left) and (not node.right):
                return dep
            if not node.left: ls.append((node.left, dep+1))
            if not node.right: ls.append((node.right, dep+1))



# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        re = [0]
        def fmin(node, d):
            if node == None: return
            if (re[0]>0 and re[0]<=d) or (node.left == None and node.right == None):
                if re[0] <= 0 or d < re[0]:
                    re[0] = d
                return
            fmin(node.left, d+1)
            fmin(node.right, d+1)
        fmin(root, 1)
        return re[0]
