#!/usr/bin/env python
# encoding: utf-8


"""
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 后半部分链表反序，10次过
class Solution(object):
    def isPalindrome(self, head):
        if head == None or head.next == None: return True
        if head.next.next == None: return head.val == head.next.val
        pf, ps = head, head
        while pf != None and pf.next != None and pf.next.next != None:
            pf = pf.next.next
            ps = ps.next
        t, pre = ps.next, ps
        while t != None:
            nt = t.next
            t.next = pre
            t, pre = nt, t
        t = pre
        while t != None and head != None:
            if t.val != head.val: return False
            if t == head or t == head.next: return True
            t, head = t.next, head.next

# 1次过，但是没用O（1)空间
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        re = []
        t = head
        while t != None:
            re.append(t.val)
            t = t.next
        return re == re[-1::-1]
