/*
 * 2个链表表示2整数，求和
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * h = new ListNode(0), *t;
        t = h;
        int sum = 0, add = 0;
        while(l1 != NULL || l2 != NULL){
            sum = 0;
            if(l1 != NULL) {sum += l1->val; l1 = l1->next;}
            if(l2 != NULL) {sum += l2->val; l2 = l2->next;}
            t->next = new ListNode((sum + add) % 10);
            add =(sum+add)/10;
            t = t->next;
        }
        if(add > 0) t->next = new ListNode(add);
        if(h->next == NULL) h->next = new ListNode(0);
        return h->next;

    }
};
