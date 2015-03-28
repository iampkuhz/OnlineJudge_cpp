/*
 * BinaryTreeInorderTraversal.cpp
 *
 *  Created on: Mar 22, 2015
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> re;
        if(root == NULL) return re;

        Rec(re, root);
        return re;
    }

    void Rec(vector<int>& re, TreeNode * top)
    {

    	if(top->left != NULL)
    	{
    		Rec(re, top->left);
    	}

    	re.push_back(top->val);

    	if(top->right != NULL)
    	{
    		Rec(re, top->right);
    	}
    }

    void test()
    {
    	TreeNode * a = new TreeNode(1);
    	TreeNode * b = new TreeNode(2);
    	TreeNode * c = new TreeNode(3);
    	a->right = b;
    	b->left = c;
    	vector<int> re = inorderTraversal(a);

    	for(int i = 0 ; i < re.size(); i ++)
    	{
    		cout << re[i] << " ";
    	}
    }
};



