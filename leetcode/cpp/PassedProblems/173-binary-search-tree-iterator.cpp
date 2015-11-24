/*
 * 173-binary-search-tree-iterator.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <stack>
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
class BSTIterator {
public:
	stack<TreeNode*> st;
	TreeNode* tmp;
    BSTIterator(TreeNode *root) {
    	tmp = root;
    	while(tmp != NULL && tmp->left != NULL){
    		st.push(tmp);
    		tmp = tmp->left;
    	}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
    	return tmp != NULL;
    }

    /** @return the next smallest number */
    int next() {
    	int v = tmp->val;
    	if(tmp->right != NULL){
    		tmp = tmp->right;
    		while(tmp->left != NULL){
    			st.push(tmp);
    			tmp = tmp->left;
    		}
    	}
    	else if(st.size() > 0){
    		tmp = st.top();
    		st.pop();
    	}
    	else tmp = NULL;
    	return v;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */



