#!/usr/bin/env python
# encoding: utf-8



"""
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 1次过
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def getp(root, tar, ls):
            ls.append(root)
            if root.val == tar: return ls
            elif root.val > tar: return getp(root.left, tar, ls)
            else: return getp(root.right, tar, ls)
        p1, p2 = getp(root, p.val, []), getp(root, q.val, [])
        for i in range(min(len(p1), len(p2))):
            if p1[i].val != p2[i].val: return p1[i-1]
        return p1[min(len(p1), len(p2))-1]

