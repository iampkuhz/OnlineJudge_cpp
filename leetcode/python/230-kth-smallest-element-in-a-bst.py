#!/usr/bin/env python
# encoding: utf-8

"""

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Show Hint
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 3次过，返回值类型、递归使用局部变量l（不要用t）

class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        lr = []
        t = root
        while t != None:
            lr.append(t)
            t = t.left
        t = None
        while k > 0:
            t = lr.pop()
            if t.right != None:
                l = t.right
                while l != None:
                    lr.append(l)
                    l = l.left
            k -= 1
        return t.val



