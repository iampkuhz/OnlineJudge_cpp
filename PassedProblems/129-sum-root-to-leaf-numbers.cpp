/*
 * 129.sum-root-to-leaf-numbers.cpp
 *
 *  Created on: Jul 11, 2015
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
    int sumNumbers(TreeNode* root) {
    	if(root == NULL)
    		return 0;
    	int sum = 0;
    	sum += getSum(root, 0);
    	return sum;
    }

    int getSum(TreeNode * root, int val)
    {
    	if(root == NULL)
    		return 0;
    	int nVal = val * 10 + root->val;
    	if(root->left == NULL && root->right == NULL)
    		return nVal;
    	return getSum(root->left, nVal) + getSum(root->right, nVal);
    }
};

