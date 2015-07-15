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
    ListNode *detectCycle(ListNode *head) {
    	ListNode * pf = head, *ps = head;
    	int stp = 0;
    	while(pf != NULL)
    	{
    		stp ++;
    		/* 2 steps */
    		pf = pf->next;
    		if(pf != NULL)
    			pf = pf->next;
    		else return NULL;
    		/* 1 step */
    		ps = ps->next;
    		if(pf == ps)
    		{
    			ListNode * p1 = head, * p2 = ps;
    			while(p1 != p2)
    			{
    				p1 = p1->next;
    				p2 = p2->next;
    			}
    			return p1;
    		}
    	}
    	return NULL;
    }
};


