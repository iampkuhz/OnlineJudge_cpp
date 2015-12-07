"""
ven a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

      After removing the second node from the end, the linked list becomes 1->2->3->5.
      Note:
      Given n will always be valid.
      Try to do this in one pass.
"""
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        if head == None:
            return None;
        fp = head; sp = head;
        while n > 0:
            fp = fp.next;
            n -= 1;
        spAh = head;
        while fp != None:
            fp = fp.next;
            spAh = sp;
            sp = sp.next;
        if sp == head:
            return head.next;
        spAh.next = sp.next;
        #print spAh.val, sp.val;
        return head;

a1= ListNode(1);
a2= ListNode(2);
a3= ListNode(3);
a4= ListNode(4);
a5= ListNode(5);
a4.next =a5;
a3.next =a4;
a2.next=a3;
a1.next=a2;
s = Solution();
r=s.removeNthFromEnd(a1, 2);
while r != None:
    print r.val,'->';
    r = r.next;
        
        
