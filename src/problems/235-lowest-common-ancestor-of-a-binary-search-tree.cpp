/*
 * 235-lowest-common-ancestor-of-a-binary-search-tree.cpp
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as
the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 *  Created on: Sep 29, 2015
 *      Author: hanzhe
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	vector<TreeNode*> p1, p2;
    	extractPath(p1, root, p);
    	extractPath(p2, root, q);
    	int i = 0;
    	while(i < p1.size() && i < p2.size() && p1[i]->val == p2[i]->val)
    		i ++;
    	return p1[i-1];
    }

    void extractPath(vector<TreeNode*> & v, TreeNode* r, TreeNode* p){
		v.push_back(r);
    	if(r->val == p->val){
    		return;
    	}
    	if(r->val > p->val)
    		extractPath(v, r->left, p);
    	else extractPath(v, r->right, p);
    }
};


