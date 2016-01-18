#!/usr/bin/env python
# encoding: utf-8

"""
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 时间上没有提升,参考网上答案
class Solution(object):
    def recoverTree(self, root):
        triple=[None,None,None] #pre,n1, n2
        def ino(root):
            if root == None:return
            ino(root.left)
            if triple[0] != None and triple[0].val > root.val:
                if triple[1] == None:
                    triple[2], triple[1] = root, triple[0]
                else:
                    triple[2] = root
            triple[0] = root
            ino(root.right)
        ino(root)
        triple[1].val,triple[2].val = triple[2].val,triple[1].val


class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        val=[]
        def visit(node):
            if node == None:
                return
            visit(node.left)
            val.append(node.val)
            visit(node.right)
        visit(root)
        val = reversed(sorted(val))
        def rewrite(node):
            if node == None:
                return
            rewrite(node.right)
            node.val = val.pop()
            rewrite(node.left)
        rewrite(root)




