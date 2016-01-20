#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
"""


# Definition for binary tree with next pointer.
# class TreeLinkNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

# 不能用`not x`判断是否是None
class Solution(object):
    def connect(self, root):
        if root == None:return
        ls = [root]
        while len(ls)>0:
            nl= []
            for i in range(len(ls)):
                if i > 0: ls[i-1].next = ls[i]
                if None !=  ls[i].left :
                    nl.append(ls[i].left)
                if None !=  ls[i].right :
                    nl.append(ls[i].right)
            ls = nl


class Solution(object):
    def connect(self, root):
        """
        :type root: TreeLinkNode
        :rtype: nothing
        """
        # 按行遍历，记录pre节点，然后更新,记录层数
        if root == None:return
        import Queue
        ls = Queue.Queue()
        ls.put([root,0])
        pre = None
        while not ls.empty():
            tp = ls.get()
            if pre != None and tp[1] > pre[1]: pre = None
            if pre != None: pre[0].next = tp[0]
            pre = tp
            if tp[0].left != None: ls.put([tp[0].left,tp[1]+1])
            if tp[0].right != None: ls.put([tp[0].right,tp[1]+1])
