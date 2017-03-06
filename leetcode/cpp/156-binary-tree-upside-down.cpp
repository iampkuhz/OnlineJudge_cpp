/*
 * 4次过，都是没有考虑root=NULL的情况，开始的时候题目没理解题意
 *
 *Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

For example:
Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1

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
    TreeNode * update(TreeNode* node, TreeNode* f, TreeNode* r){
        TreeNode *nl =  node->left, *nr = node->right;
        TreeNode * newF = node;
        if(nl != NULL)
            newF = update(nl, node, nr);
        node->left = r;
        node->right = f;
        return newF;
    }

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == NULL) return root;
        return update(root, NULL, NULL);
    }
};
