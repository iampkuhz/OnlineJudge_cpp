/*
 *
 * 找bst上最近的k个节点
 * 先遍历所有点O(n)，再二分查找最近的l，r O(logn), 然后l，r找k个点O(k)
 * 1. 其实可以便利所有点O(n)，vector<int, double> 记录值和差值，然后按照差值排序，取前k个
 * 2. 可以优先队列排序
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

class Solution {
    vector<int> nodev;
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        // 1. visit all node
        dfs(root);
        // 2. get target index
        int sz = nodev.size();
        int l = 0, r = nodev.size()-1;
        while(l+1 < r){
            int m = (l+r)/2;
            if(nodev[m] < target) l = m;
            else r = m;
        }
        vector<int> re;
        int tk = 0;
        while(tk < k){
            tk ++;
            if(l >= 0 && r < sz){
                if(fabs(target - nodev[r]) > fabs(target - nodev[l])){
                    re.push_back(nodev[l--]);
                }else re.push_back(nodev[r++]);
            }
            else if(l >= 0)
                re.push_back(nodev[l--]);
            else re.push_back(nodev[r++]);
        }
        return re;
    }
    void dfs(TreeNode * node){
        if(node == NULL) return;
        dfs(node->left);
        nodev.push_back(node->val);
        dfs(node->right);
    }
};
