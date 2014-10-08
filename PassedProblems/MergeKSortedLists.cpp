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

struct ListNode {
     int val;
     ListNode * next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct myComp
{
	bool operator ()(const ListNode* s1, const ListNode* s2)
	{
		if(s1 == NULL || s2 == NULL)
			return false;
		if(s1->val > s2->val)
			return true;
		return false;
	}
};
class Solution {
public:
    ListNode * mergeKLists(vector<ListNode *> &lists) {
    	if(lists.empty())
    		return NULL;
    	ListNode * head = NULL;
    	ListNode * tmp;
    	if(lists.size() > 0)
    		make_heap(lists.begin(), lists.end(), myComp());
    	while(lists.size() > 0)
    	{
    		int last = lists.size()-1;
    		cerr << "last:" << last << endl;
    		if(lists[0] == NULL)
    		{
    			pop_heap(lists.begin(), lists.end(), myComp());
    			lists.pop_back();
    			continue;
    		}
    		if(last > 0)
    			cerr << lists[0]->val << "--" << lists[1]->val << endl;
    		else cerr << lists[0]->val << "--"  << endl;
    		int minValue = lists[0]->val;
    		cerr << "minvalue:" << minValue << endl;
    		// min tree to last
    		pop_heap(lists.begin(), lists.end(), myComp());
    		//cerr << "minvalue:" << minValue << " size:" << lists.size()<< endl;
    		if(head == NULL){
    			head = new ListNode(minValue);
    			tmp = head;
    		}
    		else{
    			ListNode * next = new ListNode(minValue);
    			cerr << next->val << endl;
    			tmp->next = next;
    			tmp = next;
    		}
    		if(lists[last]->next == NULL)
    		{
    			cerr << "*****:" << lists[last]->val << endl;
    			lists.pop_back();
    		}
    		else{
    			cerr << last << " list value0:" << lists[last]->val << " " << lists[last]->next->val << endl;
    			lists[last] = lists[last]->next;
    			lists.push_back(lists[last]);
    			push_heap(lists.begin(), lists.end(), myComp());
    		}

    	}
    	tmp = head;
    	cout <<"head:" << head->val << endl;
    	while(tmp != NULL)
    		cout << tmp->val << " ";
    	cout << endl;
    	return head;
    }
};

