#!/usr/bin/env python
# encoding: utf-8

"""

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# 两次过,递归边界没有考虑清楚
class Solution(object):
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        re={inorder[i]:i for i in range(len(inorder))}
        def tree(ia,ib, pa,pb):
            if ia > ib: return None
            ind = re[postorder[pb]]
            root = TreeNode(postorder[pb])
            root.left = tree(ia,ind-1,pa,pa+ind-ia-1)
            root.right = tree(ind+1,ib,pa+ind-ia,pb-1)
            return root
        l = len(inorder)
        return tree(0,l-1,0,l-1)
