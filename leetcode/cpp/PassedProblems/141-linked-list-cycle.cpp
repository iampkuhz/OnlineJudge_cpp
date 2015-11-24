/*
 * 141-linked-list-cycle.cpp
 *
 *  Created on: Jul 14, 2015
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
    bool hasCycle(ListNode *head) {
    	ListNode * pf = head, *ps = head;
    	while(pf != NULL)
    	{
    		/* 2 steps */
    		pf = pf->next;
    		if(pf != NULL)
    			pf = pf->next;
    		else return false;
    		/* 1 step */
    		ps = ps->next;
    		if(pf == ps)
    			return true;
    	}
    	return false;
    }
};


