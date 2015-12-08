"""
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None :
            return head;
        nHead = ListNode(0);
        nHead.next = head;
        p1 = head;
        pre = nHead;
        while p1 != None and p1.next != None:
            p2 = p1.next;
            p3= p2.next;
            pre.next=p2;
            p2.next=p1;
            p1.next=p3;
            ##########
            pre = p1;
            p1 = p3;
        return nHead.next;

        
