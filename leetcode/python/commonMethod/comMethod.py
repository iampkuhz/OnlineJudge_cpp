
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Convertor(object):
    def __init__(self):
        return;

    def List2ListNode(self, ls):
        if len(ls) == 0:
            return None;
        head = ListNode(ls[0]);
        t = head;
        for i in range(1,len(ls)):
            tt = ListNode(ls[i]);
            t.next = tt;
            t = tt;
        return head;

    def printListNode(self, head):
        if head == None:
            return;
        print head.val,;
        head = head.next;
        while head != None:
            print '->', head.val,;
            head = head.next;
        print;
        return;


        

