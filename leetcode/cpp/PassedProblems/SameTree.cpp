/*
 * SameTree.cpp
 *
 *  Created on: Mar 22, 2015
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
    	if(p == NULL || q == NULL)
    	{
    		if(p != NULL || q != NULL)
    			return false;
    		return true;
    	}
    	if(p->val != q->val)
    		return false;

    	bool re = isSameTree(p->left, q->left);
    	if(re == true)
    		re = isSameTree(p->right, q->right);

    	return re;
    }

};



