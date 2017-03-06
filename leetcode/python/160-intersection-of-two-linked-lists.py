#!/usr/bin/env python
# encoding: utf-8

"""
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 1次过，速度快
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if headA == None or headB == None: return None
        # 先看终点一样不
        p1, p2, l1, l2 = headA, headB, 0, 0
        while p1.next != None:
            p1, l1 = p1.next, l1 + 1
        while p2.next != None:
            p2, l2 = p2.next, l2 + 1
        if p1 != p2: return None

        # 再走到第一个交点
        p1, p2 = headA, headB
        dif = l1 - l2
        if dif > 0:
            while dif > 0:
                dif, p1 = dif - 1, p1.next
        else:
            while dif != 0:
                dif, p2 = dif + 1, p2.next
        while p1 != p2:
            p1, p2 = p1.next, p2.next
        return p1

