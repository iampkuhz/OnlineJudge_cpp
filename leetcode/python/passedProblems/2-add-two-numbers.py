# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2;
        elif l2 is None:
            return l1;
        re = ListNode(0);
        p = re;
        add = 0;
        while(l1 is not None or l2 is not None):
            sum = add;
            if l1 is not None:
                sum += l1.val;
                l1 = l1.next;
            if l2 is not None:
                sum += l2.val;
                l2 = l2.next;
            add = sum / 10;
            sum %= 10;
            re.next = ListNode(sum);
            re = re.next;
        if add > 0:
            re.next = ListNode(add);
        return p.next;
