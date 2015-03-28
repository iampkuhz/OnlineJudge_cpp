/*
 * ValidateBinarySearchTree.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: hanzhe
 */
#include <iostream>
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
    bool isValidBST(TreeNode *root) {
    	if(root == NULL) return true;

        bool re = Rec(root, false, root->val, false, root->val);
        return re;
    }

    bool Rec(TreeNode * r, bool min, int minTh, bool max, int maxTh)
    {
    	if(r == NULL) return true;

    	//cout << r->val << " " << min << " " << minTh << " " << max << " " << maxTh << endl;

    	bool re = true;
    	if((min && r->val <= minTh) || (max && r->val >= maxTh))
    		return false;

    	bool omax = max;
    	int omaxTh = maxTh;

    	if(max) maxTh = Min(maxTh, r->val);
    	else maxTh = r->val;
		re = Rec(r->left, min, minTh, true, maxTh);
		if(re == false) return false;

		if(min) minTh = Max(minTh, r->val);
		else minTh = r->val;
		re = Rec(r->right, true, minTh, omax, omaxTh);

		return re;
    }

    int Min(int a, int b)
    {
    	return a > b ? b : a;
    }
    int Max(int a, int b)
    {
    	return a > b ? a : b;
    }

    void test()
    {
    	TreeNode * a = new TreeNode(3);
    	TreeNode * b = new TreeNode(1);
    	TreeNode * c = new TreeNode(5);
    	TreeNode * d = new TreeNode(0);
    	TreeNode * e = new TreeNode(2);
    	TreeNode * f = new TreeNode(4);
    	TreeNode * g = new TreeNode(6);
    	a->left = b;
    	a->right = c;
    	b->left = d;
    	b->right = e;
    	c->left = f;
    	c->right = g;
    	cout << isValidBST(a) << endl;
    }
};



