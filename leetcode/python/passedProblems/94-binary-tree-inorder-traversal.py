#!/usr/bin/env python
# encoding: utf-8

"""
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# 4次提交过,
class Solution(object):
    def inorderTraversal(self, root):
        if root == None:
            return []
        ls = [[root.right,1],[root, 0], [root.left, 1]]
        re = []
        while len(ls):
            top = ls.pop()
            if top[0] == None:
                continue;
            if top[1] == 1:
                ls.append([top[0].right,1])
                ls.append([top[0],0])
                ls.append([top[0].left,1])
            else:
                re.append(top[0].val)
        return re





# 一次过
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        re = []
        def dfs(node):
            if node == None:
                return
            dfs(node.left)
            re.append(node.val)
            dfs(node.right)
        dfs(root)
        return re



