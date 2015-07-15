/*
 * 143-reorder-list.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    void reorderList(ListNode* head) {
    	if(head == NULL || head->next == NULL)
    		return;
        /*1. find middle node*/
    	ListNode * pf = head, *ps = head;
    	while((pf!= NULL && pf->next != NULL && pf->next->next != NULL))
    	{
    		pf = pf->next->next;
    		ps = ps->next;
    	}

    	/*2. reverse sec half nodes */
    	ListNode * ah = ps->next;
    	ps->next = NULL;
    	ListNode * n = ah->next;
    	ah->next = NULL;
    	while(n != NULL)
    	{
    		ListNode * nn = n->next;
    		n->next = ah;
    		ah = n;
    		n = nn;
    	}

    	/*3. merge 2 list of nodes*/
    	ListNode * h1 = head;
    	while(ah != NULL)
    	{
    		ListNode* nah = ah->next;
    		ListNode* nh = h1->next;
    		ah->next = nh;
    		h1->next = ah;
    		ah = nah;
    		h1 = nh;
    	}
    }

    void test()
    {
    	ListNode * p1 = new ListNode(1), * p2 = new ListNode(2);
    	p1->next = p2;
    	reorderList(p1);
    	while(p1 != NULL)
    	{
    		cout << p1->val;
    		p1 = p1->next;
    	}
    }
};


