/*
 * Laucher.cpp
 *
 *  Created on: 2014年10月7日
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include "src/problems/GenerateParenthsis.cpp"
using namespace std;
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
int main()
{
	testGenerateParenthsis();
	//testValidParentheses();
	//testRemoveRemoveNthNodeFromEndofList();
	return 0;
}




/*
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
