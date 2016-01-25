#!/usr/bin/env python
# encoding: utf-8

"""
Sort a linked list in O(n log n) time using constant space complexity.
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 网上的方法 250ms -> 140ms
class Solution(object):
    def sortList(self, head):
        ls = []; t = head
        while t != None:
            ls.append(t.val); t = t.next
        ls.sort()
        t = head
        for v in ls:
            t.val = v
            t = t.next
        return head

# 2次过，第一次超时，第二次三段分就过了，时间比较好
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 快排最合适
        if head == None: return None
        left, right = ListNode(0), ListNode(0)
        tl, tr = left, right
        piv, t, tp = head, head.next, head
        while t != None:
            nt = t.next
            t.next = None
            if t.val > piv.val:
                tr.next = t
                tr = tr.next
            elif t.val == piv.val:
                tp.next = t
                tp = tp.next
            else:
                tl.next = t
                tl = tl.next
            t = nt
        left = self.sortList(left.next)
        right = self.sortList(right.next)
        tp.next = right
        if left == None: return piv
        t = left
        while t.next != None: t = t.next
        t.next = piv
        return left

