/*
 * FlattenBinaryTreetoLinkedList.cpp
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
    void flatten(TreeNode *root) {
        if(root == NULL) return;

        Rec(root);
    }

    TreeNode * Rec(TreeNode * root)
    {
    	if(root->left == NULL)
    	{
    		return root->right != NULL ? Rec(root->right) : root;
    	}
    	TreeNode *rr = root->right;
    	root->right = root->left;
    	root->left = NULL;
    	TreeNode * last = Rec(root->right);
    	last->left = NULL;
    	last->right = rr;
    	return Rec(last);
    }

    void test()
    {

    }
};



