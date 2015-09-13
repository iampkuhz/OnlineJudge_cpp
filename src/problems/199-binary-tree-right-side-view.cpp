/*
 * 199-binary-tree-right-side-view.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
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
class nodeLev{
public:
	int l;
	TreeNode * n;
	nodeLev(int tl, TreeNode * tn) : l(tl), n(tn){}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> re;
    	if(root == NULL) return re;
    	queue<nodeLev*> nodes;
    	nodes.push(new nodeLev(1,root));
    	int tl = 0;
    	while(nodes.size() > 0){
    		nodeLev * top = nodes.front();
    		if(top->l > tl){
    			re.push_back(top->n->val);
    			tl ++;
    		}
    		if(top->n->right != NULL)
    			nodes.push(new nodeLev(top->l + 1, top->n->right));
    		if(top->n->left != NULL)
    			nodes.push(new nodeLev(top->l + 1, top->n->left));
    		nodes.pop();
    	}
    	return re;
    }
};


