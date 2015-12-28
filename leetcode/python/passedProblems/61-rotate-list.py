#!/usr/bin/env python
# encoding: utf-8

"""
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head
        tail,preNode, kNode, size = head, head, head.next, 1
        while tail.next is not None:
            tail = tail.next
            size += 1
        k = (size - k % size) % size
        if k == 0: return head

        while k > 1:
            preNode = kNode
            kNode = kNode.next
            k -= 1
        preNode.next = None
        tail.next = head
        return kNode

