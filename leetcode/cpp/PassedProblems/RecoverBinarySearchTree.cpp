/*
 * RecoverBinarySearchTree.cpp
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
	int Ind1, Ind2, v1, v2;
	int seq;
    void recoverTree(TreeNode *root) {
    	// 1. tree 2 array
    	vector<int> vs;
    	Tree2Array(root, vs);

    	// 2. find 2 error
    	Ind1 = -1;
    	for(int i = 0 ; i < vs.size(); i ++)
    	{
    		if(Ind1 < 0 && i < vs.size() -1 && vs[i] > vs[i+1])
    			Ind1 = i;
    		if(i > 0 && vs[i] < vs[i-1])
    			Ind2 = i;
    	}
    	v1 = vs[Ind1], v2 = vs[Ind2];
    	// 3. fix error
    	seq = 0;
    	Fix(root);
    }

    void Fix(TreeNode * root)
    {
    	if(root == NULL) return;

    	Fix(root->left);
    	if(seq == Ind1) root->val = v2;
    	else if(seq == Ind2) root->val = v1;
    	seq ++;
    	Fix(root->right);
    }

    void Tree2Array(TreeNode * root, vector<int> & vs)
    {
    	if(root == NULL) return;
    	Tree2Array(root->left, vs);
    	vs.push_back(root->val);
    	Tree2Array(root->right, vs);
    }
};



