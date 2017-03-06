#!/usr/bin/env python
# encoding: utf-8


"""
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 3次过
class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        re = []
        def fn(node, ls):
            if node == None: return
            ls.append(node.val)
            if node.left == None and node.right == None:
                re.append(ls[:])
                ls.pop()
                return
            fn(node.left, ls)
            fn(node.right, ls)
            ls.pop()
        fn(root, [])
        re2 = []
        for x in re:
            re2.append("->".join(str(t) for t in x))
        return re2


