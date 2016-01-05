#!/usr/bin/env python
# encoding: utf-8

"""
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None: return head
        pre, t = head, head.next
        while t != None:
            if t.val == pre.val:
                pre.next, t = t.next, t.next
            else:
                t, pre = t.next, t
        return head

