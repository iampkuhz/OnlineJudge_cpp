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
};



