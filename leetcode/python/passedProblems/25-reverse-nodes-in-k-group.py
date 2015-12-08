"""

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if k == 1:
            return head;
        pf = head; tk = k-1;
        while tk > 0 and pf != None:
            tk -= 1;
            pf = pf.next;
        nH = ListNode(0);
        nH.next = head;
        pre = nH;
        ps = head;
        while pf != None:
            self.reverseGroup(pre, ps, pf);
            pre = ps;
            # bug: ps is None!!
            ps = ps.next;
            pf = ps;
            tk = k-1;
            while tk > 0 and pf != None:
                tk -= 1;
                pf = pf.next;
        return nH.next;

        
    def reverseGroup(self, pre, s, e):
        nx = e.next;
        t = s;
        tp = pre;
        while True:
            tn = t.next;
            t.next = tp;
            if t == e:
                break;
            tp = t;
            t = tn;
        pre.next = e;
        s.next = nx;

from commonMethod.comMethod import *
l = ListNode(3);
cv = Convertor();
s=Solution();
head = s.reverseKGroup(cv.List2ListNode([1,2]), 2);
print cv.printListNode(head);
