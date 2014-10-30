/*
 * Laucher.cpp
 *
 *  Created on: 2014年10月7日
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include "src/problems/SubstringwithConcatenationofAllWords.cpp"
using namespace std;

int main()
{
	Solution * one = new Solution();
	one->test();
	//testRemoveDumplicatesFromSortedArray();
	//testSwapNodesInPairs();
	//testMergeKSortedLists();
	//testValidParentheses();
	//testRemoveRemoveNthNodeFromEndofList();
	return 0;
}



/*
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
}*/
/*
 *
void testMergeKSortedLists()
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
 *
void testGenerateParenthsis()
{
	Solution * one = new Solution();
	int size;
	while(cin >> size){
		vector<string> result = one->generateParenthesis(size);
		for(unsigned int i = 0; i < result.size(); i ++)
			cout << result.at(i) << endl;
	}

}

void testValidParentheses()
{
	Solution * one = new Solution();
	string input;
	while(cin >> input)
		cout << one->isValid(input) << endl;
	return;
}
 *
void testRemoveRemoveNthNodeFromEndofList()
{
	Solution * one = new Solution();
	ListNode* head = new ListNode();
	head->val = 1;
	ListNode* next = new ListNode();
	next->val = 2;
	head->next = next;
	next->next = new ListNode();

	next = next->next;
	next->val = 3;
	next->next = new ListNode();

	next = next->next;
	next->val = 4;
	next->next = new ListNode();

	next = next->next;
	next->val = 5;
	next->next = NULL;

	ListNode *result = one->removeNthFromEnd(head, 2);
	while(result != NULL)
	{
		cout << result->val << " ";
		result = result->next;
	}
}
*/
