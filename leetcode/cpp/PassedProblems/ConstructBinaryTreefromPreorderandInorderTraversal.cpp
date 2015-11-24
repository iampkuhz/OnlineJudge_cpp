/*
 * ConstructBinaryTreefromPreorderandInorderTraversal.cpp
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	TreeNode *root = NULL;
    	if(preorder.size() < 1) return root;

    	root = new TreeNode(preorder[0]);
    	int size = preorder.size();
    	RecBuild(root, preorder, 0, size-1, inorder, 0, size-1);
    	return root;
    }

    void RecBuild(TreeNode * root, vector<int> & pre, int pS, int pE, vector<int> & in, int iS, int iE)
    {
    	int v = pre[pS];
    	root->val = v;
    	cout  << v << endl;
    	int iV = -1;
    	//bool fin = false;
    	for(int i = iS; i <= iE; i ++)
    		if(in[i] == v){
    			iV = i;
    			//fin = true;
    			break;
    		}
    	//if(fin == false) return;
    	if(iV > iS)
    	{
    		root->left = new TreeNode(0);
    		RecBuild(root->left, pre, pS+1, iV-iS+pS, in, iS, iV-1);
    	}
    	if(iV < iE)
    	{
    		root->right = new TreeNode(0);
    		RecBuild(root->right, pre, iV-iS+pS+1, pE, in, iV+1, iE);
    	}
    }

    void test()
    {
    	int a[]={4,2,1,5,3,6}, b[]={1,2,4,3,5,6};
    	vector<int> ino(a,a+6);
    	vector<int> preo(b,b+6);
    	TreeNode * root = buildTree(preo, ino);

    	outputNode(root);
    }

    void outputNode(TreeNode * root)
    {
    	if(root == NULL) return;
    	cout << "root:" << root->val;
    	if(root->left == NULL) cout << " l:null";
    	    	else
    	    	{
    	    		cout <<" l:" << root->left->val;
    	    	}
    	if(root->right == NULL) cout << " r:null";
    	else
    	{
    		cout <<" r:" << root->right->val;
    	}
    	cout << endl;
		outputNode(root->left);
		outputNode(root->right);

    }
};



