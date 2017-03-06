#!/usr/bin/env python
# encoding: utf-8


"""

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 1次过
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        def isM(m, s):
            if m == None: return False
            if m == s: return True
            return isM(m.left, s) or isM(m.right, s)

        if isM(p, q): return p
        if isM(q, p): return q
        while root:
            if root == q or root == p: return root
            if isM(root.left, q) and isM(root.left, p): root = root.left
            elif isM(root.right, q) and isM(root.right, p): root = root.right
            else: return root
        return None


# 4次过，getP写错了
class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def getP(node, pp):
            if node == None: return None
            if node == pp: return [node]
            lls = getP(node.left, pp)
            if lls != None: return [node] + lls
            rls = getP(node.right, pp)
            if rls != None: return [node] + rls
            return None
        ls1 = getP(root, p)
        ls2 = getP(root, q)
        if ls1 == None or ls2 == None: return None
        l1, l2 = len(ls1), len(ls2)
        for i in range(min(l1, l2)):
            if ls1[i] != ls2[i]: return ls1[i-1]
        return ls1[min(l1,l2)-1]




