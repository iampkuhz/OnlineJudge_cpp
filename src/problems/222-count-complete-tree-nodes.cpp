/*
 * 222-count-complete-tree-nodes.cpp
 * Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled,
and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.
 *
 *  Created on: Sep 23, 2015
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
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    int countNodes(TreeNode* root) {
    	if(root == NULL)
    		return 0;
    	if(leftLevel(root) == rightLevel(root))
    		return (1 << leftLevel(root)) - 1;
    	else return countNodes(root->left) + countNodes(root->right) + 1;
    }
    int leftLevel(TreeNode* root){
    	if(root == NULL)
    		return 0;
    	return leftLevel(root->left) + 1;
    }
    int rightLevel(TreeNode* root){
    	if(root == NULL)
    	    return 0;
    	return rightLevel(root->right) + 1;
    }
};

