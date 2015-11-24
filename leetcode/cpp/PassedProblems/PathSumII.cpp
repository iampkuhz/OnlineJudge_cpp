/*
 * PathSumII.cpp
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

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
    	vector<vector<int> > re;
    	if(root == NULL) return re;

    	vector<int> seq;
    	Rec(re, root, sum, seq);
    	return re;
    }

    void Rec(vector<vector<int> > &re, TreeNode * root, int sum, vector<int>& seq)
    {
    	if(root == NULL)
    	{
    		return;
    	}

    	sum -= root->val;
    	seq.push_back(root->val);
    	if(sum == 0 && root->left == NULL && root->right == NULL)
    	{
    		re.push_back(seq);
    	}
    	Rec(re, root->left, sum, seq);
    	Rec(re, root->right, sum, seq);
    	seq.pop_back();
    }
};



