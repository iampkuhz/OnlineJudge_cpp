/*
 * ConvertSortedArraytoBinarySearchTree.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
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

    void test()
    {
    	int a[] ={1,2,3,4,5,6,7,8,9};
    	vector<int> va(a,a+9);
    	TreeNode * r = sortedArrayToBST(va);
    	outputNode(r);
    }
    void outputNode(TreeNode * root)
    {
    	if(root == NULL) return;
    	cout << "root:" << root->val;
    	if(root->left == NULL) cout << " l:null";
    	    	else
    	    	{
    	    		cout <<" l:" << root->left->val;
    	    	}
    	if(root->right == NULL) cout << " r:null";
    	else
    	{
    		cout <<" r:" << root->right->val;
    	}
    	cout << endl;
		outputNode(root->left);
		outputNode(root->right);

    }
};



