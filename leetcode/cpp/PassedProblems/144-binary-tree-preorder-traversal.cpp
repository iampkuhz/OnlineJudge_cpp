/*
 * 144-binary-tree-preorder-traversal.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
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
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> re;
    	rec(re, root);
    	return re;
    }

    void rec(vector<int> & re, TreeNode* root)
    {
    	if(root == NULL)
    		return;
    	re.push_back(root->val);
    	rec(re, root->left);
    	rec(re, root->right);
    }
};


