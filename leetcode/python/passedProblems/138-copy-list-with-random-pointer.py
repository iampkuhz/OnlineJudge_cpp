#!/usr/bin/env python
# encoding: utf-8

"""
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
"""


# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

# 网上的方法, 两次过，忘记返回值了
class Solution(object):
    def copyRandomList(self, head):
        mmap = {None:None}
        t = head
        while t != None:
            mmap[t] = RandomListNode(t.label)
            t = t.next
        pre, t = None, head
        while t != None:
            if pre != None: mmap[pre].next = mmap[t]
            mmap[t].random = mmap[t.random]
            pre, t = t, t.next
        return mmap[head]


# 两次过，忘记前后链表了，光顾着random
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if head == None: return None
        n2o = {head:RandomListNode(head.label)}
        t = head; npre = None
        while t != None:
            nt = n2o[t] if t in n2o else RandomListNode(t.label)
            if t.random != None and t.random not in n2o:
                n2o[t.random] = RandomListNode(t.random.label)
            if t.random != None:
                nt.random = n2o[t.random]
            if npre != None: npre.next = nt
            t, npre = t.next, nt
        return n2o[head]


