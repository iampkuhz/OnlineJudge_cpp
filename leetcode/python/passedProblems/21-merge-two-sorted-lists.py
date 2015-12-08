#Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2;
        elif l2 is None:
            return l1;
        head = l1; p1 = l1.next; p2 = l2;
        if l1.val > l2.val:
            head = l2;
            p1 = l1;
            p2 = l2.next;
        p = head;
        while p1 != None and p2 != None:
            if p1.val > p2.val:
                p.next = p2;
                p2 = p2.next;
            else:
                p.next = p1;
                p1 = p1.next;
            p = p.next;
        p.next = p1 if p1 != None else p2;
        return head;

        
