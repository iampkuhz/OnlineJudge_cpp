#!/usr/bin/env python
# encoding: utf-8

"""
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None



# 速度超级慢，调了很多次才过
class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if None == head: return None
        rmost=[[TreeNode(head.val),0]]
        head = head.next
        #cnt = 0
        while None != head:
            nnode = TreeNode(head.val)
            rmost[-1][0].right = nnode
            rmost.append([nnode,0])
            l = len(rmost)
            rd = 1
            for i in range(l-2, -1, -1):
                if rmost[i][1] < rd -1:
                    #if cnt < 10:
                    #    print [[r[0].val,r[1]] for r in rmost], rmost[i][0].val
                    #    cnt += 1
                    rmost[i][0].right = rmost[i+1][0].left
                    rmost[i+1][0].left = rmost[i][0]
                    if i > 0: rmost[i-1][0].right = rmost[i+1][0]
                    rmost[i+1][1] = max(1+rmost[i][1],1+rmost[i+1][1])
                    rd = 1+rmost[i+1][1]
                    rmost.pop(i)
                    rd = max(rd, len(rmost)-i) # 可能有问题
                else: rd = max(rd, rmost[i][1])+1
            head = head.next
        return rmost[0][0]

