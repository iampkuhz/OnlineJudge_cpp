/*
 *
 * 1次过
 * 找从上往下最长的连续子序列
 *Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    /
   2
  /
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
    int maxL = 0;
public:
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) return 0;
        getM(root->left, root->val, 1);
        getM(root->right, root->val, 1);
        return maxL;
    }
    void getM(TreeNode * node, int fVal, int seqLen){
        if(node == NULL || node->val != fVal + 1){
            maxL = maxL > seqLen ? maxL : seqLen;
            if(node != NULL){
                getM(node->right, node->val, 1);
                getM(node->left, node->val, 1);
            }
        }
        else if(node != NULL){
            getM(node->left, fVal + 1, seqLen + 1);
            getM(node->right, fVal + 1, seqLen + 1);
        }
    }

};
