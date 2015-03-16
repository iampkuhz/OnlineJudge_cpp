/*
 * RemoveNthNodeFromEndofList.cpp
 *
 *  Created on: 2014年10月7日
 *      Author: hanzhe
 */
#include<iostream>
using namespace std;
class ListNode {
public:
	int val;
	ListNode * next;
};
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
    	ListNode* nPlus = head;
    	int dis2End = 0;
    	ListNode* tmp = head;
    	while(tmp != NULL)
    	{

    		if(dis2End <= n)
    			dis2End ++;
    		else{
    			nPlus = nPlus->next;
    		}
    		//cout << tmp->val << " " << nPlus->val << endl;
    		tmp = tmp->next;
    	}
    	if(dis2End > n)
    	{
    		nPlus->next = nPlus->next->next;
    		return head;
    	}
    	else if(dis2End == n)
    		return head->next;
    	else {
    		return head;
    	}
    }
    void test()
    {
    	Solution * one = new Solution();
    	ListNode* head = new ListNode();
    	head->val = 1;
    	ListNode* next = new ListNode();
    	next->val = 2;
    	head->next = next;
    	next->next = new ListNode();

    	next = next->next;
    	next->val = 3;
    	next->next = new ListNode();

    	next = next->next;
    	next->val = 4;
    	next->next = new ListNode();

    	next = next->next;
    	next->val = 5;
    	next->next = NULL;

    	ListNode *result = one->removeNthFromEnd(head, 2);
    	while(result != NULL)
    	{
    		cout << result->val << " ";
    		result = result->next;
    	}
    }
};



