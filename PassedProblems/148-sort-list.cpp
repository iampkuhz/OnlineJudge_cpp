/*
 * 148-sort-list.cpp
 *
 *  Created on: Jul 15, 2015
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
        	return NULL;
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head)
    {
    	if(head == NULL || head->next == NULL)
    		return head;
    	ListNode* pf = head, * ps = head, * pre = NULL;
    	while(pf != NULL && pf->next != NULL)
    	{
    		pf = pf->next->next;
    		pre = ps;
    		ps = ps->next;
    	}
    	pre->next = NULL;
    	/*at list 2 elements, each half is not NULL*/
    	ListNode* h1 = mergeSort(head);
    	ListNode* h2 = mergeSort(ps);
    	return merge(h1, h2);
    }

    ListNode * merge(ListNode* h1, ListNode* h2)
    {
//    	cout << h1->val << h2->val << endl;
    	ListNode * tmp = new ListNode(0);
    	ListNode * p = tmp;
    	while(h1 && h2)
    	{
    		if(h1->val < h2->val)
    		{
    			tmp->next = h1;
    			h1 = h1->next;
    		}
    		else{
    			tmp->next = h2;
    			h2 = h2->next;
    		}
			tmp = tmp->next;
    	}
    	if(h1)
    		tmp->next = h1;
    	else tmp->next = h2;
    	p = p->next;
    	tmp = NULL;
    	delete tmp;
    	return p;
    }

    void test()
    {
    	ListNode* p1 = new ListNode(3);
    	ListNode* p2 = new ListNode(4);
    	p1->next = p2;
    	ListNode* p = sortList(p1);
    	while(p != NULL){
    		cout << p->val << " ";
    		p = p->next;
    	}

    }
};

