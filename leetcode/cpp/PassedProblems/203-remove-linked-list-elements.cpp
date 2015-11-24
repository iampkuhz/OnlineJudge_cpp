/*
 * 203-remove-linked-list-elements.cpp
 *
 *  Created on: Sep 13, 2015
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
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode* re = NULL, * tail, *tmp = head;
    	while(tmp != NULL){
    		if(tmp->val != val){
    			if(re == NULL){
    				re = tmp;
    			}
    			else{
    				tail->next = tmp;
    			}
				tail = tmp;
    		}
    		tmp = tmp->next;
    	}
    	tail->next = NULL;
    	return re;
    }
};


