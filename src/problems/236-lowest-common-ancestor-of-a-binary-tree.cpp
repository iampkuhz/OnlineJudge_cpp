/*
 * 236-lowest-common-ancestor-of-a-binary-tree.cpp
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w
as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
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
#include <stack>
#include <vector>
#include "../dataType/TreeNode.cpp"
using namespace std;
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(root == NULL || p == NULL || q == NULL) return NULL;
    	if(root == p || root == q) return root;
    	TreeNode* l = lowestCommonAncestor(root->left, p, q);
    	TreeNode* r = lowestCommonAncestor(root->right, p, q);
    	if(l && r) return root;
    	return l ? l :r;
    }
    void test(){
    	TreeNode * t1 = new TreeNode(1);
    	TreeNode * t2 = new TreeNode(2);
    	TreeNode * t3 = new TreeNode(3);
    	t1->left = t2;
    	t1->right = t3;
    	cout << lowestCommonAncestor(t1, t2, t3)->val << endl;
    }
};

