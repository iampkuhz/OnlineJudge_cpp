/*
 * 230-kth-smallest-element-in-a-bst.cpp
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

 *
 *  Created on: Sep 28, 2015
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
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    	stack<TreeNode*> st;
    	NodeLeft2Stack(root, st);
    	int size = 1;
    	while(size < k){
    		TreeNode* t = st.top();
    		st.pop();
    		size ++;
    		NodeLeft2Stack(t->right, st);
    	}
    	return st.top()->val;
    }
    void NodeLeft2Stack(TreeNode* r, stack<TreeNode*>& st){
    	while(r!= NULL){
    		st.push(r);
    		r = r->left;
    	}
    }
};


