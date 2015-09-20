/*
 * 206-reverse-linked-list.cpp
 *
 *  Created on: Sep 14, 2015
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
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
using namespace std;
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    	if(head == NULL || head->next == NULL)
    		return head;
    	ListNode * tPre = head, *tH = head->next;
    	tPre->next = NULL;
    	while(tH != NULL){
    		ListNode * tn = tH->next;
    		tH->next = tPre;
    		tPre = tH;
    		tH = tn;
    	}
    	return tPre;
    }
};


