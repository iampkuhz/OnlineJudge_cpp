#!/usr/bin/env python
# encoding: utf-8

"""
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 1次过
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        while head!= None and head.val == val:
            head = head.next
        if head == None: return None
        t, pre = head.next, head
        while t != None:
            if t.val == val:
                pre.next = t.next
                t = t.next
                continue
            t, pre = t.next, t
        return head

