/*
 * 3次过，但是有更好的答案：记录从上往下走的时候最近一次左拐的节点，就是后继节点
 * 查找点，记录父节点的路径，然后反向查找最近的、含有右子树的节点，找到这个节点右子树上最小的点就是答案；要求右子树不在这个路径上
 *Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.

*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode *> path;
        path.push_back(root);
        while(root->val != p->val){
            if(root->val > p->val) root = root->left;
            else root = root->right;
            path.push_back(root);
        }
        TreeNode * sc = root->right;
        if(sc == NULL){
            int sz = path.size();
            for(int i = sz-2; i >= 0; i --)
                if(path[i]->left == path[i+1]){
                    return path[i];
                }
            return NULL;
        }
        while(sc->left != NULL)
            sc = sc->left;
        return sc;
    }
};
