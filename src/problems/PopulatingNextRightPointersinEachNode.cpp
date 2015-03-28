/*
 * PopulatingNextRightPointersinEachNode.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if(root == NULL) return;
    	vector<TreeLinkNode*> nodes;
    	nodes.push_back(root);
    	vector<TreeLinkNode*> nnodes;
    	Rec(nodes, nnodes);
    }

    void Rec(vector<TreeLinkNode*> nodes, vector<TreeLinkNode*> nnodes)
    {
    	if(nodes.size() < 1) return;

    	for(int i = 0 ; i < nodes.size(); i ++)
    	{
    		if(i < nodes.size() -1) nodes[i]->next = nodes[i+1];
    		if(nodes[i]->left != NULL)
    			nnodes.push_back(nodes[i]->left);
    		if(nodes[i]->right != NULL)
    			nnodes.push_back(nodes[i]->right);
    	}
    	nodes.clear();
    	Rec(nnodes, nodes);
    }
};


