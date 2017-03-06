/*
 * 3次过，应该保留：二分查找的最后点、后继节点、前继节点，最后比较这三个点的大小，下面思路不对：
 * 看题意，只要二分查找该值，记录其后继节点，最后比较2个节点取其一即可
 *Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
 */

#include <iostream>
#include <algorithm>
#include <math.h>

using anemspace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        TreeNode * suc = NULL, * pre = NULL;
        while(true){
            if(root->val > target){
                if(root->left != NULL){
                    suc = root;
                    root = root->left;
                }
                else break;
            }
            else if(root->val == target)
                return root->val;
            else{
                if(root->right != NULL){
                    pre = root;
                    root = root->right;
                }
                else break;
            }
        }
        int re = root->val;
        double fabsMin = fabs(re - target);
        if(suc != NULL && fabs(suc->val - target) < fabsMin){
            fabsMin = fabs(suc->val - target);
            re = suc->val;
        }
        if(pre != NULL && fabs(pre->val - target) < fabsMin)
            return  pre->val;
        return re;

    }
};
