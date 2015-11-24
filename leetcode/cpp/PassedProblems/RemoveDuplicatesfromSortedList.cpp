/*
 * RemoveDuplicatesfromSortedList.cpp
 *
 *  Created on: Mar 15, 2015
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
    ListNode *deleteDuplicates(ListNode *head) {
    	if(head == NULL || head->next == NULL) return head;

    	ListNode * re = head, * tmp = head, *next = head->next;
    	while(tmp->next != NULL)
    	{
    		next = tmp->next;
    		if(next->val == tmp->val)
    			tmp->next = next->next;
    		else tmp = next;
    	}
    	tmp->next = NULL;
    	return re;
    }

    void test()
    {
    	ListNode *l1 = new ListNode(1), *l2 = new ListNode(1), *l3 = new ListNode(2);
    	l1->next = l2;
    	l2->next = l3;
    	ListNode *re1 = deleteDuplicates(l1);
    	while(re1 != NULL){
    		cout << re1->val << " ";
    		re1 = re1->next;
    	}cout << endl;


    	ListNode *l4 = new ListNode(1), *l5 = new ListNode(1), *l6 = new ListNode(2), *l7 = new ListNode(3),
    			 *l8 = new ListNode(3);
    	l4->next = l5;
    	l5->next = l6;
    	l6->next = l7;
    	l7->next = l8;
    	ListNode *re2 = deleteDuplicates(l5);
    	while(re2 != NULL){
    		cout << re2->val << " ";
    		re2 = re2->next;
    	}
    	cout << endl;


    }
};



