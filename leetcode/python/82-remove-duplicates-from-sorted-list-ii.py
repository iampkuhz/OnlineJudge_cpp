#!/usr/bin/env python
# encoding: utf-8

"""
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.


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
        nh = ListNode(0)
        nh.next = head

        pre = nh
        # remove left
        t = head
        while t is not None:
            val = t.val
            if t.next is not None and t.next.val == val:
                while t is not None and t.val == val:
                    pre.next = t.next
                    t = t.next
            else:
                pre = t
                t = t.next
        return nh.next


