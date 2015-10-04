/*
 * 257-binary-tree-paths.cpp
 *
 *  Created on: Oct 4, 2015
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
#include <sstream>
using namespace std;
#include <vector>
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> re;
        if(root == NULL)
        	return re;
        vector<int> tPath;
        find(re, root, tPath);
        return re;
    }

    void find(vector<string> & re, TreeNode * r, vector<int>& path){
    	if(r == NULL)
    		return;
    	path.push_back(r->val);
    	if(r->left == NULL && r->right == NULL){
    		ostringstream os;
    		os << path[0];
    		for(int i = 1 ; i < path.size(); i ++)
    			os << "->" << path[i];
    		re.push_back(os.str());
    	}
    	find(re, r->left, path);
    	find(re, r->right, path);
    	path.pop_back();
    }
};


