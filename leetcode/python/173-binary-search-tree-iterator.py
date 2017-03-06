#!/usr/bin/env python
# encoding: utf-8

"""
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.


"""


# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# 3次过
# 1. left写成next
# 2. return nd.val 写成 return nd (Output Limit Exceeded)
class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.root = root
        self.lnodes = []
        while root!= None:
            self.lnodes.append(root)
            root = root.left



    def hasNext(self):
        """
        :rtype: bool
        """
        return len(self.lnodes) > 0


    def next(self):
        """
        :rtype: int
        """
        nd = self.lnodes.pop()
        t = nd.right
        while t != None:
            self.lnodes.append(t)
            t = t.left
        return nd.val


# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
