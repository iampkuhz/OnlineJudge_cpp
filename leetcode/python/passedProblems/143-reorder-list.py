#!/usr/bin/env python
# encoding: utf-8

"""
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 常规方法：split2段，后段reverse，2段合并
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        # 数组存贮位置, 不是好的方法（速度还行）
        if head == None: return
        ls = []
        tmp = head
        while tmp != None:
            ls.append(tmp)
            tmp = tmp.next
        for i in range(len(ls)/2):
            ls[i].next = ls[len(ls)-i-1]
            ls[len(ls)-i-1].next = ls[i+1]
        ls[len(ls)/2].next = None



