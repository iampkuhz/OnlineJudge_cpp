/*
 * BinaryTreeMaximumPathSum.cpp
 *
 *  Created on: Mar 30, 2015
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
	int maxSum;
	bool find;
    int maxPathSum(TreeNode *root) {
    	find = false;
    	rec(root);
    	return maxSum;
    }

    int rec(TreeNode * root)
    {
    	if(root == NULL) return 0;
    	int sum = root->val;
    	int left = rec(root->left) ;
    	int ri = rec(root->right);
    	sum += 0 < left ? left : 0;
    	sum += 0 < ri ? ri : 0;

    	maxSum = (find == false || maxSum < sum) ? sum : maxSum;
    	find = true;

    	int add = left < ri ? ri : left;
    	add = add < 0 ? 0: add;
    	return root->val + add ;
    }

    void test()
    {

    }
};



