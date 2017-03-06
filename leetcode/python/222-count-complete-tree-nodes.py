#!/usr/bin/env python
# encoding: utf-8


"""

Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 看答案，左右递归做, 8次过
class Solution(object):
    def countNodes(self, root):
        if root == None: return 0
        lm, rm = root, root
        depl, depr = 0, 0
        while lm.left != None: lm = lm.left; depl += 1
        while rm.right != None: rm = rm.right; depr += 1
        if depl == depr: return 2**(depl+1)-1
        else: return self.countNodes(root.left) + self.countNodes(root.right) + 1


# 超时
class Solution(object):
    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # 叶节点个数×2-1+（存在单子节点）
        cnt = [0, 0]
        def dfs(node):
            if node == None: return
            if node.left == None or node.right == None:
                if (node.left != None and node.right != None):
                    cnt[1] = 1
                else: cnt[0] += 1
            else:
                dfs(node.left)
                dfs(node.right)
        dfs(root)
        return cnt[0]*2 - 1 + cnt[1]

