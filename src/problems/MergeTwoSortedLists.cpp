/*
 * MergeTwoSortedLists.cpp
 *
 *  Created on: Mar 28, 2015
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	ListNode * t1 = l1, *t2 = l2, *t = NULL, * re = NULL;
    	while(t1 != NULL || t2 != NULL)
    	{
    		/*if(t1 != NULL) cout <<"t1:" << t1->val << " ";
    		if(t2 != NULL) cout <<"t2:" << t2->val;
    		cout << endl;*/

    		if(t1 != NULL && t2 != NULL)
    		{
    			if(t1->val < t2->val)
    			{
    				Add(t, re, t1);
    			}
    			else
    			{
    				Add(t, re, t2);
    			}
    		}
    		else if(t1 != NULL)
    		{
    			Add(t, re, t1);
    		}
    		else if(t2 != NULL)
    		{
    			Add(t, re, t2);
    		}
    		//cout << t->val << "  : " << re->val << endl;
    	}

    	return re;
    }

    void Add(ListNode * &t, ListNode *& re, ListNode * &tt)
    {
    	if(t == NULL)
    	{
    		re = tt;
    		t = tt;
    	}
    	else
    	{
    		t->next =  tt;
    		t = tt;
    	}
		tt = tt->next;
    }

    void test()
    {
    	int num1 [] = {-10,-9,-9,-3,-1,-1,0};
    	ListNode * r1 = Array2ListNode(num1, 7);
    	int num2 [] = {-9,-6,-5,-4,-2,2,3};
    	ListNode * r2 = Array2ListNode(num2, 7);
    	int num3 [] = {-3,-3,-2,-1,0};
    	ListNode * r3 = Array2ListNode(num3, 5);

    	ListNode * result = mergeTwoLists(r1, r2);

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



