#!/usr/bin/env python
# encoding: utf-8

"""
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def buildTree(self, preorder, inorder):
        value2ind = {}
        for i in range(len(inorder)):
            value2ind[inorder[i]] = i
        def bd(pa,pb, ia,ib):
            if pb < pa: return None
            v = preorder[pa]
            llen = value2ind[v]-ia
            root= TreeNode(v)
            root.left=bd(pa+1,pa+llen, ia,ia+llen-1)
            root.right=bd(pa+llen+1,pb, ia+llen+1,ib)
            return root
        l=len(preorder)
        if l == 0:return None
        return bd(0,l-1,0,l-1)




# 超内存
class Solution(object):
    self.size = 0
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if len(inorder) == 0: return None
        root = TreeNode(preorder[0])
        self.size += 1
        print self.size
        if len(inorder) == 1: return root
        ind = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1:ind+1], inorder[0:ind])
        root.right = self.buildTree(preorder[ind+1:], inorder[ind+1:])
        return root

