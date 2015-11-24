/*
 * MaximumDepthofBinaryTree.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {

    	if(root == NULL) return 0;

    	vector<TreeNode*> rLevel;
    	rLevel.push_back(root);

    	vector<TreeNode*> nLevel;


    	int level = 0;
    	while(rLevel.size() > 0)
    	{
    		int size = rLevel.size();
    		//cout << level << ":" << size << endl;
    		// 2. make next level
    		nLevel.clear();
    		for(int i = 0 ; i < size; i ++)
    		{
    			TreeNode * p = rLevel[i];

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
    		level ++;
    	}
    	return level;

    }

    void test()
    {
    	cout << maxDepth(NULL) << endl;

    	TreeNode * a = new TreeNode(3);
    	cout << maxDepth(a) << endl;

    	TreeNode * b = new TreeNode(1);
    	TreeNode * c = new TreeNode(3);
    	a->left = b;
    	a->right = c;
    	cout << maxDepth(a) << endl;

    	TreeNode * d = new TreeNode(7);
    	TreeNode * e = new TreeNode(2);
    	cout << maxDepth(a) << endl;
    	TreeNode * f = new TreeNode(5);
    	TreeNode * g = new TreeNode(-1);
    	b->left = d;
    	b->right = e;
    	c->left = f;
    	c->right = g;
    	cout << maxDepth(a) << endl;
    }
};



