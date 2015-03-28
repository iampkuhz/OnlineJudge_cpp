/*
 * BalancedBinaryTree.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <cmath>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
	bool bal;
    bool isBalanced(TreeNode *root) {
        bal = true;
        if(root == NULL) return true;

        return b(root);
    }

    bool b(TreeNode * root)
    {
    	if(root == NULL) return true;

    	int ll = getLevel(root->left);
    	int lr = getLevel(root->right);

    	if(bal == false) return false;
    	return abs(ll - lr) <= 1;
    }

    int getLevel(TreeNode * root)
    {
    	if(root == NULL || bal == false) return 0;
    	int ll = getLevel(root->left);
    	int lr = getLevel(root->right);

    	if(abs(ll-lr) > 1)
    	{
    		bal = false;
    		return 0;
    	}

    	return ll > lr ? ll + 1 : lr + 1;
    }
};



