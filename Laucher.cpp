/*
 * Laucher.cpp
 *
 *  Created on: 2014年10月7日
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include "src/problems/SwapNodesInPairs.cpp"
using namespace std;
void testSwapNodesInPairs()
{
	Solution *one = new Solution();

	ListNode * result = one->swapPairs();
}
int main()
{
	//testMergeKSortedLists();
	//testValidParentheses();
	//testRemoveRemoveNthNodeFromEndofList();
	return 0;
}




/*
 *
void testMergeKSortedLists()
{
	Solution * one = new Solution();
	ListNode * r1 = new ListNode(1);
	ListNode * next = new ListNode(4);
	r1->next = next;
	ListNode * tmp = new ListNode(5);
	next->next = tmp;

	ListNode * r2 = new ListNode(2);
	next = new ListNode(3);
	r2->next = next;
	tmp = new ListNode(6);
	next->next = tmp;
	vector<ListNode*> * lists = new vector<ListNode*>;
	//cerr << "r1:" << r1->val << endl;
	//cerr << "r2:" << r2->val << endl;
	lists->push_back(r1);
	//cerr << "lists size:" << lists->size() << endl;
	lists->push_back(r2);
	//cerr << "lists size:" << lists->size() << endl;
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
