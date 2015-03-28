/*
 * SymmetricTree.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <cmath>
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

class myNode
{
public:
	TreeNode * p;
	// index in binary tree
	int ind;
	myNode(TreeNode * p1, int i1)
	{
		p = p1;
		ind = i1;
	}
};
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
    	if(root == NULL) return true;

    	vector<myNode> rLevel;
    	myNode * myRoot = new myNode(root, 1);
    	rLevel.push_back(*myRoot);

    	vector<myNode> nLevel;

    	int level = 1;
    	while(rLevel.size() > 0)
    	{
    		int size = rLevel.size();
    		//cout << level << ":" << size << endl;
    		// 1. check this level;
    		for(int i = 0; i < (size+1)/2; i ++)
    		{
    			if(rLevel[i].p->val != rLevel[size - i - 1].p->val ||
    					(rLevel[i].ind + rLevel[size - i -1].ind) != (3 * pow(2, level-1) - 1))
    			{
    				return false;
    			}
    		}

    		// 2. make next level
    		nLevel.clear();
    		for(int i = 0 ; i < size; i ++)
    		{
    			TreeNode * p = rLevel[i].p;
    			int ind = rLevel[i].ind;

    			if(p->left != NULL)
    			{
    				myNode *l = new myNode(p->left, ind * 2);
    				nLevel.push_back(*l);
    			}
    			if(p->right != NULL)
    			{
    				myNode *r = new myNode(p->right, ind * 2 + 1);
    				nLevel.push_back(*r);
    			}
    		}
    		rLevel.clear();
    		rLevel.insert(rLevel.end(), nLevel.begin(), nLevel.end());

    		level ++;
    	}
    	return true;
    }

    void test()
    {
    	TreeNode * a = new TreeNode(3);
    	cout << isSymmetric(a) << endl;

    	TreeNode * b = new TreeNode(1);
    	TreeNode * c = new TreeNode(1);
    	a->left = b;
    	a->right = c;
    	cout << isSymmetric(a) << endl;

    	TreeNode * d = new TreeNode(0);
    	TreeNode * e = new TreeNode(2);
    	TreeNode * f = new TreeNode(2);
    	TreeNode * g = new TreeNode(0);
    	b->left = d;
    	b->right = e;
    	cout << isSymmetric(a) << endl;
    	c->left = f;
    	c->right = g;

    	cout << isSymmetric(a) << endl;
    }
};



