/*
 * 234-palindrome-linked-list.cpp
 * Given a singly linked list, determine if it is a palindrome.
 * Follow up:
Could you do it in O(n) time and O(1) space?
 *  Created on: Sep 28, 2015
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
#include <stack>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:

    bool isPalindrome(ListNode* head) {
    	if(head == NULL) return false;
    	if(head->next == NULL)
    		return true;
    	ListNode *f = head, *s = head;
    	while( f->next != NULL && f->next->next != NULL){
    		s = s->next;
    		f = f->next->next;
    	}
    	// reverse second half
    	f = s->next;
//		cout << f->val << endl;
    	while(f != NULL){
    		ListNode * t = f->next;
    		f->next = s;
    		s = f;
    		if(t == NULL)
    			break;
    		f = t;
    	}
//    	cout << "e" << endl;
    	s = head;
    	while(true){
//    		cout << f->val << " " << s->val << endl;
    		if(f->val != s->val)
    			return false;
    		if(f == s && f->next == s)
    			break;
    		f = f->next;
    		s = s->next;
    	}
    	return true;
    }

    bool isPalindrome_O_N_space_cost(ListNode* head) {
    	stack<int> vals;
    	ListNode * t = head;
    	while(t != NULL){
    		vals.push(t->val);
    		t = t->next;
    	}
    	t = head;
    	while(t != NULL){
    		if(t->val != vals.top())
    			return false;
    		t = t->next;
    		vals.pop();
    	}
    	return true;
    }

    void test(){
    	ListNode * l1 = new ListNode(1);
    	ListNode * l2 = new ListNode(2);
//    	l1->next = l2;
    	l2->next = l1;
    	cout << isPalindrome(l2) << endl;
    }
};

