"""
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
"""
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# bug1: [[1,1,2],[1,2,2]]返回了第一个，没有合并：
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        lens = len(lists);
        if lens == 0:
            return None;
        elif lens == 1:
            return lists[0];
        l1 = self.mergeKLists(lists[0:lens/2]);
        l2 = self.mergeKLists(lists[lens/2:]);
        return self.merge2List(l1, l2);


    def merge2List(self, l1, l2):
        if l1 is None:
            return l2;
        elif l2 is None:
            return l1;
        head = l1; p1 = l1.next; p2 = l2;
        if l1.val > l2.val:
            p1 = l1; p2 = l2.next;head = l2;
        p = head;
        while p1 != None and p2 != None:
            if p1.val < p2.val:
                p.next = p1; p1 = p1.next;
            else:
                p.next = p2; p2 = p2.next;
            p = p.next;
        p.next = p1 if p1 != None else p2;
        return head;

        

        
