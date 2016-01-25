#!/usr/bin/env python
# encoding: utf-8

"""
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# fp初始化错误，2次过,时间没问题
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None: return None
        fp, sp = head.next.next, head.next
        while fp != None:
            if fp == sp:
                tmp = head
                while tmp != sp:
                    tmp = tmp.next
                    sp = sp.next
                return tmp

            if fp.next != None:
                fp = fp.next.next
            else: return None
            sp = sp.next
        return None

