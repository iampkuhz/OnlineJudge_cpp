#!/usr/bin/env python
# encoding: utf-8

"""
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


# 100ms -> 88ms 还是不快，网上的做法
class Solution(object):
    def hasCycle(self, head):
        try:
            h1, h2 = head, head.next
            while not h1 is h2:
                h1 = h1.next
                h2 = h2.next.next
            return True
        except:
            return False

# 一次过，但是速度慢
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None or head.next == None: return False
        fp, sp = head.next.next, head.next
        while fp != None:
            if fp == sp: return True
            if fp.next != None:
                fp = fp.next.next
            else: fp = None
            sp = sp.next
        return False

