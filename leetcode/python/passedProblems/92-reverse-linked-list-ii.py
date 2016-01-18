#!/usr/bin/env python
# encoding: utf-8

"""
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if m == n: return head
        nh = ListNode(0)
        nh.next = head
        ind = 1
        pre, t, ln, lm = nh, nh.next, None, None
        while ind < m:
            pre, t, ind = t, t.next, ind+1
        lm1 = pre
        lm = t
        while ind <= n:
            nt = t.next
            t.next = pre
            t, pre = nt, t
            ind += 1
        lm.next, lm1.next = t, pre
        return nh.next





