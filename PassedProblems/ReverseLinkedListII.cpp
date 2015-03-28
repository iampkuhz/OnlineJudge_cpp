/*
 * ReverseLinkedListII.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: hanzhe
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode * n) : val(x), next(n) {}
  };

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *re = head, * tmp = head, * bm = NULL, * bn = NULL, * next, * nnext;

        int i = 1;
        while((i++) < m && tmp != NULL)
        {
        	bm = tmp;
        	tmp = tmp->next;
        }

        if(tmp == NULL) return head;
        nnext = tmp->next;
        //cout << "bm:" << bm->val << endl;

        while((i++) <= n && tmp != NULL)
        {
        	next = nnext;
        	cout << "next:" << next->val << endl;
        	if(next != NULL)
        	{
        		nnext = next->next;
        		next->next = tmp;
        	}
        	else nnext = NULL;

        	tmp = next;
        }
        bn = nnext;
        //cout << "bn:" << bn->val << endl;
        if(bm != NULL)
    	{
    		bm->next->next = bn;
    		bm->next = tmp;
    	}
    	else
    	{
    		re = tmp;
    		head->next = bn;
    	}
        return re;
    }

    void test()
    {
    	ListNode * a = new ListNode(5);
    	ListNode * b = new ListNode(4, a);
    	ListNode * c = new ListNode(3, b);
    	ListNode * d = new ListNode(2, c);
    	ListNode * e = new ListNode(1, d);

    	ListNode * re = reverseBetween(e, 1, 5);

    	while(re!= NULL)
    	{
    		cout << re->val << " ";
    		re = re->next;
    	}
    }
};



