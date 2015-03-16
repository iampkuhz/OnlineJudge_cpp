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
		if(s1 == NULL)
			return false;
		else if(s2 == NULL)
			return true;
		return s1->val > s2->val;
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
    		/*
    		cout << "list heads:" ;
    		for(int i = 0 ; i <= last ; i ++)
    		{
    			if(lists[i] == NULL)
    				cout<< "# ";
    			else cout << lists[i]->val << " ";
    		}cout << endl;*/
    		if(lists[0] == NULL)
    		{
    			pop_heap(lists.begin(), lists.end(), myComp());
    			lists.pop_back();
    			continue;
    		}
    		// min tree to last
    		pop_heap(lists.begin(), lists.end(), myComp());
    		ListNode * lastNode = lists[last];
			lists.pop_back();
    		int minValue = lastNode->val;
    		//cerr << "minvalue:" << minValue << " size:" << lists.size()<< endl;
    		if(head == NULL){
    			head = new ListNode(minValue);
    			tmp = head;
    		}
    		else{
    			ListNode * next = new ListNode(minValue);
    			tmp->next = next;
    			tmp = next;
    		}
    		if(lastNode->next != NULL)
    		{
    			//cerr << last << " list value0:" << lastNode->val << " " << lastNode->next->val << endl;lastNode = lastNode->next;
    			lists.push_back(lastNode->next);
    			push_heap(lists.begin(), lists.end(), myComp());
    		}
    	}
    	/*
    	tmp = head;
    	cout <<"head:" << head->val << endl;
    	while(tmp != NULL){
    		cout << tmp->val << " ";
    		tmp = tmp->next;
    	}cout << endl;*/
    	return head;
    }
    void test()
    {
    	Solution * one = new Solution();
    	vector<ListNode*> * lists = new vector<ListNode*>;
    	int num1 [] = {-10,-9,-9,-3,-1,-1,0};
    	ListNode * r = Array2ListNode(num1, 7);
    	lists->push_back(r);
    	lists->push_back((new ListNode(-5)));
    	lists->push_back((new ListNode(4)));
    	lists->push_back((new ListNode(-8)));
    	lists->push_back(NULL);
    	int num2 [] = {-9,-6,-5,-4,-2,2,3};
    	r = Array2ListNode(num2, 7);
    	lists->push_back(r);
    	int num3 [] = {-3,-3,-2,-1,0};
    	r = Array2ListNode(num3, 5);
    	lists->push_back(r);
    	ListNode * result = one->mergeKLists(*lists);

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


