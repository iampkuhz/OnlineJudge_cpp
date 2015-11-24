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


    void testSwapNodesInPairs()
    {
    	Solution *one = new Solution();
    	int nums[] = {1,2,3,4};
    	ListNode * input = Array2ListNode(nums, 4);
    	ListNode * result = one->swapPairs(input);
    	while(result != NULL)
    	{
    		cout << result->val << " ";
    		result = result->next;
    	}
    }
    ListNode * Array2ListNode(int nums[], int len)
    {
    	if(len < 1)
    		return NULL;
    	ListNode * head = new ListNode(nums[0]);
    	ListNode * tmp = head;
    	for(int i = 1 ; i < len; i ++)
    	{
    		ListNode * next = new ListNode(nums[i]);
    		tmp->next = next;
    		tmp = tmp->next;
    	}
    	return head;
    }
};



