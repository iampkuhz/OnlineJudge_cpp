/*
 * 4次过，
 *Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
*/
#include <iostream>
using namespace std;

class Solution {
    int cnt = 0;
public:
    int countUnivalSubtrees(TreeNode* root) {
        cnt = 0;
        icount(root);
        return cnt;
    }
    int icount(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) {
            cnt ++;
            return 1;
        }
        int cl = icount(root->left);
        int cr = icount(root->right);
        if(!((cl > 0 && root->val == root->left->val) || root->left == NULL ))
            return 0;
        if(!((cr > 0 && root->val == root->right->val) || root->right == NULL ))
            return 0;
        cnt ++;
        return cl + cr + 1;

    }
};
