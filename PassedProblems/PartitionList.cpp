/*
 * PartitionList.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
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
    ListNode *partition(ListNode *head, int x) {
    	if(head == NULL || head->next == NULL) return head;

    	ListNode * lHead = NULL, *ltmp = NULL,
    			*gHead = NULL, *gtmp = NULL, * tmp = head;
    	while(tmp != NULL)
    	{
    		//cout << "tmp:" << tmp->val << endl;
    		ListNode * next = tmp->next;
    		if(tmp->val >= x)
    			Append(gHead, gtmp, tmp);
    		else Append(lHead, ltmp, tmp);
    		//cout << "ghead:" << gHead << " " << gtmp << " lHead:" << lHead << endl;
    		tmp = next;
    	}
    	if(gtmp != NULL)
    		gtmp->next = NULL;
    	Append(lHead, ltmp, gHead);

    	return lHead;
    }

    void Append(ListNode * &head, ListNode * &tmp, ListNode * &v)
    {
    	if(v == NULL) return;
    	if(head == NULL){
    		//cout << "tmp:" << v->val << " ahead:NULL"  << endl;
    		head = v;
    		tmp = v;
    		//cout << "new tmp:" << tmp  << " v:" << v << endl;
    	}
    	else{
    		//cout << "tmp:" << v->val << " ahead:" << tmp->val << endl;
    		tmp->next = v;
    		tmp = v;
    	}
    }

    void test()
    {
    	ListNode * l1 = new ListNode(1);
    	ListNode * l2 = new ListNode(4);
    	ListNode * l3 = new ListNode(3);
    	ListNode * l4 = new ListNode(2);
    	ListNode * l5 = new ListNode(5);
    	ListNode * l6 = new ListNode(2);
    	l1->next = l2;
    	l2->next = l3;
    	l3->next = l4;
    	l4->next = l5;
    	l5->next = l6;

    	ListNode * re = partition(l1, 3);

    	while(re != NULL)
    	{
    		cout << re->val << " ";
    		re = re->next;
    	}
    }
};



