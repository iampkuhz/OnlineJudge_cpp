/*
 * ConvertSortedListtoBinarySearchTree.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> v = lNode2Vector(head);
        return sortedArrayToBST2(v);
    }

    vector<int> lNode2Vector(ListNode * head)
	{
    	vector<int> re;
    	if(head == NULL)return re;

    	while(head != NULL)
    	{
    		re.push_back(head->val);
    		head = head->next;
    	}
    	return re;
	}
    TreeNode *sortedArrayToBST2(vector<int> &num) {
    	int size = num.size();
    	if(size < 1) return NULL;

    	TreeNode * root = new TreeNode(0);
    	Rec(root, num, 0, size-1);
    	return root;
    }

    void Rec(TreeNode * root, vector<int> & num, int s, int e)
    {
    	if(s > e) return;
    	int m = (s + e)/2;
    	root->val = num[m];
    	if(s < m)
    	{
    		root->left = new TreeNode(0);
    		Rec(root->left, num, s, m-1);
    	}
    	if(e > m)
    	{
    		root->right = new TreeNode(0);
    		Rec(root->right, num, m+1, e);
    	}
    }
};



