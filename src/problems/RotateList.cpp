/*
 * RotateList.cpp
 *
 *  Created on: Mar 8, 2015
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
    ListNode *rotateRight(ListNode *head, int k) {
    	if(head == NULL) return NULL;
    	int n = 1;
    	ListNode *last = head, *pt = head;

    	while(pt->next != NULL){
    		pt = pt->next;
    		last = pt;
    		n ++;
    	}
    	int ind = (n - (k%n)) % n;
    	//cout << "ind :" << ind << " n:" << n << endl;
    	if(ind == 0 || n == 1) return head;
    	pt = head;
    	while(true){
    		if(ind == 1) break;
    		ind --;
    		pt = pt->next;
    	}
    	ListNode * t = pt->next;
    	pt->next = NULL;
    	last->next = head;
    	//cout << t->val << endl;
    	return t;
    }

    void test()
    {
    	ListNode *a = new ListNode(1),*b = new ListNode(2),*c = new ListNode(3),*d = new ListNode(4),*e = new ListNode(5);
    	a->next = b;
    	b->next = c;
    	c->next = d;
    	d->next = e;
    	ListNode *re = rotateRight(a, 0);
    	while(re != NULL){
    		cout << re->val << " " ;
    		re = re->next;
    	}cout << endl;
    	re = rotateRight(a, 2);
    	while(re != NULL){
    		cout << re->val << " " ;
    		re = re->next;
    	}cout << endl;

    	re = rotateRight(a, 20);
    	while(re != NULL){
    		cout << re->val << " " ;
    		re = re->next;
    	}cout << endl;
    }
};


