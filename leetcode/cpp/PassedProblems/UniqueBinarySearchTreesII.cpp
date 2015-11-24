/*
 * UniqueBinarySearchTreesII.cpp
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
    vector<TreeNode *> generateTrees(int n) {
    	vector<vector<TreeNode *> > sets;

    	vector<TreeNode *> set0;
    	set0.push_back(NULL);
    	sets.push_back(set0);

    	TreeNode * a = new TreeNode(1);
    	vector<TreeNode *> set1;
    	set1.push_back(a);
    	sets.push_back(set1);

    	if(n < 2) return sets[n];

    	for(int i = 2 ; i <= n; i ++)
    	{
    		Generate(sets, i);
    	}

    	vector<TreeNode *> re = Convert2Single(sets[n]);
    	return re;
    }

    vector<TreeNode *> Convert2Single(vector<TreeNode *> set)
    {
    	vector<TreeNode *> re;
    	for(int i = 0 ; i < set.size(); i ++)
    	{
    		TreeNode * root = new TreeNode(1);
    		Convert(root, set[i], 1);
    		re.push_back(root);
    	}
    	return re;
    }

    int Convert(TreeNode * tRoot, TreeNode * tTmpl, int startNr)
    {
    	if(tTmpl->left != NULL)
    	{
    		tRoot->left = new TreeNode(1);
    		startNr = Convert(tRoot->left, tTmpl->left, startNr);
    	}
    	tRoot->val = startNr;

    	startNr ++;

    	if(tTmpl->right != NULL)
    	{
    		tRoot->right = new TreeNode(1);
    		startNr = Convert(tRoot->right, tTmpl->right, startNr);
    	}
    	return startNr;
    }

    void Generate(vector<vector<TreeNode *> >& sets, int size)
    {
    	vector<TreeNode *> re;

    	for(int i = 0 ; i < size; i ++)
    	{
    		vector<TreeNode *> setL = sets[i];
    		vector<TreeNode *> setR = sets[size - 1 - i];

    		for(int j = 0 ; j < setL.size(); j ++)
    			for(int k = 0; k < setR.size(); k ++)
    			{
    				TreeNode * root = new TreeNode(1);
    				root->left = setL[j];
    				root->right = setR[k];
    				re.push_back(root);
    			}
    	}
    	//cout << "size:" << size << ", totalFormatNr:" << re.size() << endl;
    	sets.push_back(re);
    }

    void test()
    {
    	vector<TreeNode *> re = generateTrees(3);

    	for(int i = 0 ; i < re.size() ; i ++)
    	{
    		TreeNode * r = re[i];
    		output(r);
    		cout << endl;
    	}
    }

    void output(TreeNode * r)
    {
    	if(r == NULL) return;

    	output(r->left);

    	cout << "v:" << r->val;
    	if(r->left != NULL)
    		cout << " l:" << r->left->val;
    	else cout << " l:null";

    	if(r->right != NULL)
    		cout << " r:" << r->right->val;
    	else cout << " r:null";

    	cout << endl;

    	output(r->right);

    }
};



