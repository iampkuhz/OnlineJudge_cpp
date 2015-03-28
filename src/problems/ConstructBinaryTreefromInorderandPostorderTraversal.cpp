/*
 * ConstructBinaryTreefromInorderandPostorderTraversal.cpp
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    	TreeNode *root = NULL;
    	if(postorder.size() < 1) return root;

    	int size = postorder.size();
    	root = new TreeNode(postorder[size-1]);
    	RecBuild(root, postorder, 0, size-1, inorder, 0, size-1);
    	return root;
    }

    void RecBuild(TreeNode * root, vector<int> & pos, int pS, int pE, vector<int> & in, int iS, int iE)
    {
    	int v = pos[pE];
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
    		RecBuild(root->left, pos, pS, iV-iS+pS-1, in, iS, iV-1);
    	}
    	if(iV < iE)
    	{
    		root->right = new TreeNode(0);
    		RecBuild(root->right, pos, iV-iS+pS, pE-1, in, iV+1, iE);
    	}
    }


    void test()
    {
    	int a[]={4,2,1,5,3,6}, b[]={4,2,5,6,3,1};
    	vector<int> ino(a,a+6);
    	vector<int> pos(b,b+6);
    	TreeNode * root = buildTree(ino, pos);

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


