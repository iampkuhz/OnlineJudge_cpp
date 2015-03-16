/*
 * RemoveDuplicatesfromSortedListII.cpp
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

    	ListNode * re = NULL, *rehead = NULL, * tmp = head, * next = head->next;
    	bool dup = false;
    	while(next != NULL)
    	{
    		//cout << next->val << " tmp:" << tmp->val << " dup:" << dup << endl;
    		if(next->val != tmp->val){
    			if(dup == false){
    				//cout << "insert: " << tmp->val << endl;
    				if(re == NULL){
    					re = tmp;
    					rehead = re;
    				}
    				else {
    					re->next = tmp;
    					re = tmp;
    				}
    			}
				tmp = next;
				next = next->next;
				dup = false;
    		}
    		else{
    			//cout << "dup!" << endl;
    			dup = true;
    			next = next->next;
    		}
    		//cout << " dup:" << dup << endl;
    	}
    	if(dup == false){
			if(re == NULL){
				re = tmp;
				rehead = re;
			}
    		else {
    			re->next = tmp;
    			re = tmp;
    		}
    	}
    	if(re != NULL)re->next = NULL;
    	return rehead;
    }

    void test()
    {
    	ListNode *l1 = new ListNode(1), *l2 = new ListNode(1), *l3 = new ListNode(1),
    			 *l11 = new ListNode(2), *l12 = new ListNode(3);
    	l1->next = l2;
    	l2->next = l3;
    	l3->next = l11;
    	l11->next = l12;
    	ListNode *re1 = deleteDuplicates(l1);
    	while(re1 != NULL){
    		cout << re1->val << " ";
    		re1 = re1->next;
    	}cout << endl;


    	ListNode *l4 = new ListNode(1), *l5 = new ListNode(2), *l6 = new ListNode(3),
    			*l7 = new ListNode(3), *l8 = new ListNode(4), *l9 = new ListNode(4),
				*l10 = new ListNode(5);
    	l4->next = l5;
    	l5->next = l6;
    	l6->next = l7;
    	l7->next = l8;
    	l8->next = l9;
    	l9->next = l10;
    	ListNode *re2 = deleteDuplicates(l4);
    	while(re2 != NULL){
    		cout << re2->val << " ";
    		re2 = re2->next;
    	}
    	cout << endl;


    }
};



