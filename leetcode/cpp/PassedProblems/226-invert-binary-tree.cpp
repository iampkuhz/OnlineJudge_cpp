/*
 * 226-invert-binary-tree.cpp
 *
 *  Created on: Sep 24, 2015
 *      Author: hanzhe
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if(root == NULL)
    		return root;
    	TreeNode * l = root->left;
    	root->left = root->right;
    	root->right = l;
    	invertTree(root->left);
    	invertTree(root->right);
    	return root;
    }
};


