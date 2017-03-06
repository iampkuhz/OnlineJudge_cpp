#!/usr/bin/env python
# encoding: utf-8


"""
Reverse a singly linked list.
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


# 4次过，不难其实
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        t = head
        re = []
        while t != None:
            re.append(t.val)
            t = t.next
        t = head; i = 0
        re.reverse()
        while t != None:
            t.val = re[i]
            t = t.next
            i += 1
        return head
