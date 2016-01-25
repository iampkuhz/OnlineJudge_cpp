#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# 没有看答案，但是参考了前一题的答案,一次过
class Solution(object):
    def postorderTraversal(self, root):
        ans, nds = [], [[root,1]]
        while len(nds) > 0:
            nd = nds.pop()
            if nd[0] != None:
                if nd[1] == 1:
                    nds.append([nd[0],0])
                    if nd[0].right != None: nds.append([nd[0].right, 1])
                    if nd[0].left != None: nds.append([nd[0].left, 1])
                else: ans.append(nd[0].val)
        return ans



# 递归一次过，但是不用递归不会做
class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        re = []
        def dfs(node):
            if node == None: return
            dfs(node.left)
            dfs(node.right)
            re.append(node.val)
        dfs(root)
        return re
