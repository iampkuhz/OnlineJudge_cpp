/*
 * 竖着从左往右输出
 * 拿结构体记录
 *Examples:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its vertical order traversal as:
[
  [9],
  [3,15],
  [20],
  [7]
]
Given binary tree [3,9,20,4,5,2,7],
    _3_
   /   \
  9    20
 / \   / \
4   5 2   7
return its vertical order traversal as:
[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]
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
struct tri{
    int v;
    int x;
    int y;
    int nr;
};
class Solution {
    vector<tri> nds;
    static bool myCmp(tri & t1, tri & t2){
        if(t1.y != t2.y) return t1.y < t2.y;
        else if(t1.x != t2.x) return t1.x < t2.x;
        return t1.nr < t2.nr;
    }
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        sort(nds.begin(), nds.end(), myCmp);
        vector<vector<int>> re;
        vector<int> vy;
        int sz = nds.size();
        if(sz == 0) return re;
        vy.push_back(nds[0].v);
        int lasty = nds[0].y;
        for(int i = 1 ; i < sz; i ++){
            if(nds[i].y != lasty){
                re.push_back(vy);
                vy = vector<int>();
                lasty = nds[i].y;
            }
            vy.push_back(nds[i].v);
        }
        re.push_back(vy);
        return re;
    }
    int cnt = 0;
    void dfs(TreeNode * node, int x, int y){
        if(node == NULL) return;
        tri trin = {node->val, x, y, cnt};
        cnt ++;
        nds.push_back(trin);
        dfs(node->left, x+1, y-1);
        dfs(node->right, x+1, y+1);
    }
};
