/*
 * PopulatingNextRightPointersinEachNodeII.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
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

    	TreeLinkNode * nhead = NULL, *nt = NULL, *t = root;

    	while(t != NULL)
    	{
    		Add(t->left, nhead, nt);
    		Add(t->right, nhead, nt);
    		t = t->next;
    	}
    	connect(nhead);
    }


    void Add(TreeLinkNode * &node, TreeLinkNode* &head, TreeLinkNode* &t)
    {
    	if(node == NULL) return;
    	if(t == NULL)
    	{
    		head = t = node;
    	}
    	else
    	{
    		t->next = node;
    		t = node;
    	}
    }
};



