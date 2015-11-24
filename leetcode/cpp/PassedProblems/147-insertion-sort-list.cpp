/*
 * 147-insertion-sort-list.cpp
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
    ListNode* insertionSortList(ListNode* head) {
    	if(head == NULL)
    		return head;
    	ListNode * last = head;
    	while(last->next != NULL)
    		last = last->next;
    	while(last != head)
    	{
//    		ListNode* t = head;
//    		while(t != NULL){
//    			cout << t->val << " ";
//    			t = t->next;
//    		}
//    		cout << "last:" << last->val << endl;

    		ListNode* tp = head;
    		ListNode* tpre = NULL;
    		ListNode* tn = tp->next;
    		while(tn != NULL)
    		{
//    			cout << "tn:" << tn->val << " " << endl;
    			if(tn->val < tp->val){
    				if(head == tp)
    					head = tn;
    				if(last == tn)
    					last = tp;
    				tp->next = tn->next;
    				tn->next = tp;
    				if(tpre != NULL){
    					tpre->next = tn;
    				}

        			if(tn == last){
        				last = tp;
        				break;
        			}
    				tpre = tn;
    				tn = tp->next;
//            		ListNode* t = head;
//            		while(t != NULL){
//            			cout << t->val << " ";
//            			t = t->next;
//            		}
//            		cout << "last0:" << last->val << endl;
    			}
    			else
    			{
        			if(tn == last){
        				last = tp;
        				break;
        			}
    				tpre = tp;
	    			tp = tn;
	    			tn = tn->next;
    			}

    		}
//    		t = head;
//    		while(t != NULL){
//    			cout << t->val << " ";
//    			t = t->next;
//    		}
//    		cout << "last:" << last->val << endl;
    	}
    	return head;
    }

    void test()
    {
    	ListNode* p1 = new ListNode(3);
    	ListNode* p2 = new ListNode(4);
    	ListNode* p3 = new ListNode(1);
//    	ListNode* p4 = new ListNode(2);
//    	ListNode* p5 = new ListNode(5);
    	p1->next = p2;
    	p2->next = p3;
//    	p3->next = p4;
//    	p4->next = p5;
    	ListNode* p = insertionSortList(p1);
    	while(p != NULL){
    		cout << p->val << " ";
    		p = p->next;
    	}
    }
};


