/*

 * SwapNodesInPairs.cpp
 *
 *  Created on: 2014年10月8日
 *      Author: hanzhe
 */
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode * next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
    	if(head == NULL)
    		return NULL;
    	if(head->next == NULL)
    		return head;

    	ListNode * result = head->next;
    	ListNode * tmp = head->next->next;
    	result->next = head;
    	head->next = tmp;
    	ListNode * pt = head->next;
    	ListNode * bef = head;
    	ListNode * nex;
    	while(pt != NULL){
    		if(pt->next == NULL)
    			break;
    		tmp = pt->next;
    		nex = tmp->next;
    		bef->next = tmp;
    		tmp->next = pt;
    		pt->next = nex;
    		bef = pt;
    		pt = nex;
    	}
    	return result;
    }
};



