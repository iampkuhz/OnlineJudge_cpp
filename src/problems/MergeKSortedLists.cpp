/*
 * MergeKSortedLists.cpp
 *
 *  Created on: 2014年10月7日
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode {
public:
	int val;
	ListNode * next;
	ListNode(){
		val = 0;
		next = NULL;
	}
	ListNode(int v){
		val = v;
		next = NULL;
	}
	ListNode(int v, ListNode * nex){
		val = v;
		next = nex;
	}
};
struct myComp
{
	bool operator()(const ListNode& s1, const ListNode & s2)
	{
		if(s1.val < s2.val)
			return true;
		return false;
	}
};
class Solution {
public:
    ListNode * mergeKLists(vector<ListNode *> &lists) {
    	ListNode * head = NULL;
    	ListNode * tmp;
    	while(lists.size() > 1)
    	{
    		make_heap(lists.begin(), lists.end(), myComp());
    		int minValue = lists[0]->val;
    		if(head == NULL){
    			head = new ListNode(minValue);
    			tmp = head;
    		}
    		else{
    			ListNode * next = new ListNode(minValue);
    			tmp->next = next;
    			tmp = next;
    		}
    		if(lists[0]->next == NULL)
    			lists.erase(lists.begin());
    		else lists[0] = lists[0]->next;
    	}
    	return head;
    }
};



