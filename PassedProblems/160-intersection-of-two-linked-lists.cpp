/*
 * 160-intersection-of-two-linked-lists.cpp
 *
 *  Created on: Jul 15, 2015
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(headA == NULL || headB == NULL)
    		return NULL;
    	int * a = new int[2];
    	ListNode* lastA = NULL, * lastB = NULL;
    	lastA = getLast(headA, 0, a);
    	lastB = getLast(headB, 1, a);
    	ListNode* ta = headA, *tb = headB;
    	int gap = a[0] - a[1];
    	if(gap > 0)
    		while(gap --)
    			ta = ta->next;
    	else
    	{
    		gap = -gap;
    		while(gap --)
    			tb = tb->next;
    	}
    	while(ta != tb)
    	{
    		ta = ta->next;
    		tb = tb->next;
    	}
    	return ta;
    }

    ListNode * getLast(ListNode * head, int i, int* a)
    {
    	int stp = 0;
    	while(head->next != NULL)
    	{
    		stp ++;
    		head = head->next;
    	}
    	a[i] = stp;
    	return head;
    }

    void test()
    {
    	int a = 0;
    	while(a--)
    		cout << a << endl;
    }
};

