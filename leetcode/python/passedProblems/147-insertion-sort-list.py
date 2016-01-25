#!/usr/bin/env python
# encoding: utf-8

"""

Sort a linked list using insertion sort.
"""


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# 不满足题意,但是快
class Solution(object):
    def insertionSortList(self, head):
        re = []
        t = head
        while t != None:
            re.append(t.val)
            t = t.next
        re.sort()
        i = 0; t = head
        while t != None:
            t.val = re[i]
            i += 1; t = t.next
        return head

# 一次过，速度超级慢
class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 插入排序
        if head == None: return head
        head, tail, tmp = head, head, head.next
        head.next = None
        while tmp != None:
            ntmp = tmp.next
            t = head; pre = None
            while t != None:
                if t.val > tmp.val: break
                t, pre = t.next, t
            if pre == None:
                tmp.next = head
                head = tmp
            else:
                pre.next = tmp
                tmp.next = t
            tmp = ntmp
        return head
