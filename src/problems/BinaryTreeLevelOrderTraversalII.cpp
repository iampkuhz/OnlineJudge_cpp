/*
 * BinaryTreeLevelOrderTraversalII.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
    	vector<vector<int> > re;

    	if(root == NULL) return re;

    	vector<TreeNode*> rLevel;
    	rLevel.push_back(root);

    	vector<TreeNode*> nLevel;

    	vector<int> r;

    	while(rLevel.size() > 0)
    	{
    		int size = rLevel.size();
    		//cout << level << ":" << size << endl;
    		r.clear();
    		// 2. make next level
    		nLevel.clear();
    		for(int i = 0 ; i < size; i ++)
    		{
    			TreeNode * p = rLevel[i];
    			r.push_back(p->val);

    			if(p->left != NULL)
    			{
    				nLevel.push_back(p->left);
    			}
    			if(p->right != NULL)
    			{
    				nLevel.push_back(p->right);
    			}
    		}
    		rLevel.clear();
    		rLevel.insert(rLevel.end(), nLevel.begin(), nLevel.end());
    		re.push_back(r);
    	}
    	reverse(re.begin(), re.end());
    	return re;
    }

    void test()
    {
    	TreeNode * a = new TreeNode(3);

    	TreeNode * b = new TreeNode(1);
    	TreeNode * c = new TreeNode(3);
    	a->left = b;
    	a->right = c;

    	TreeNode * d = new TreeNode(7);
    	TreeNode * e = new TreeNode(2);
    	TreeNode * f = new TreeNode(5);
    	TreeNode * g = new TreeNode(-1);
    	b->left = d;
    	b->right = e;
    	c->left = f;
    	c->right = g;

    	vector<vector<int> > re = levelOrderBottom(a);

    	for(int i = 0 ; i < re.size(); i ++)
    	{
    		for(int j = 0; j < re[i].size(); j ++)
    			cout << re[i][j] << " ";
    		cout << endl;
    	}
    }
};




