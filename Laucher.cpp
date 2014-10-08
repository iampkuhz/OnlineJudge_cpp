/*
 * Laucher.cpp
 *
 *  Created on: 2014年10月7日
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include "src/problems/MergeKSortedLists.cpp"
using namespace std;
/*
void testMergeKSortedLists()
{
	Solution * one = new Solution();
	ListNode * r1 = new ListNode(1);
	ListNode * r2 = new ListNode(2);
	vector<ListNode*> * lists;
	lists->push_back(r1);
	lists->push_back(r2);
	ListNode * result = one->mergeKLists(*lists);

}*/
int main()
{
	testMergeKSortedLists();
	//testValidParentheses();
	//testRemoveRemoveNthNodeFromEndofList();
	return 0;
}




/*
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
