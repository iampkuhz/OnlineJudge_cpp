/*
 * 145-binary-tree-postorder-traversal.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: hanzhe
 */


#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> re;
    	rec(re, root);
    	return re;
    }
    void rec(vector<int>& re, TreeNode* root)
    {
    	if(root == NULL)
    		return;
    	rec(re, root->left);
    	rec(re, root->right);
    	re.push_back(root->val);
    }
};


