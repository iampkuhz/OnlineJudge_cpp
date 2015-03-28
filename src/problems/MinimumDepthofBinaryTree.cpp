/*
 * MinimumDepthofBinaryTree.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */

#include <iostream>
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
    int minDepth(TreeNode *root) {
    	if(root == NULL) return 0;
    	if(root->left == NULL && root->right == NULL)
    		return 1;
    	int re = -1;
    	int l = minDepth(root->left);
    	re = (l > 0 && (l < re || re < 0)) ? l : re;
    	int r = minDepth(root->right);
    	re = (r > 0 && (r < re || re < 0)) ? r : re;

    	return re + 1;
    }
};



