#!/usr/bin/env python
# encoding: utf-8


"""
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.


"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


# 5次过：p[0].left,p[0].right忘记判断是否为None, str->root 跳过第一个
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root == None: return '[null]'
        # bfs, [node, level]，node可能为None,记录前一个level是否都是None了
        re, ls, levelCnt, lev = [], [[root, 1]], 1, 0
        while len(ls) > 0:
            p = ls.pop(0)
            if lev != p[1]:
                if levelCnt <= 0:
                    break
                lev, levelCnt = p[1], 0
            if p[0] != None:
                re.append(str(p[0].val))
                ls.append([p[0].left, p[1]+1])
                ls.append([p[0].right, p[1]+1])
                if p[0].left != None: levelCnt += 1
                if p[0].right != None: levelCnt += 1
            else:
                re.append('null')
        return '[' + ','.join(re) + ']'


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        :type data: str
        :rtype: TreeNode
        """
        data = data[1:-1]
        if len(data) < 1 or data == 'null': return None
        ls = [x for x in data.split(',')]
        head = TreeNode(int(ls[0]))
        ls.pop(0)
        ns = [head]
        while len(ls) > 0:
            tpn = ns.pop(0)
            tpv = ls.pop(0)
            if tpv != 'null':
                lf = TreeNode(int(tpv))
                tpn.left = lf
                ns.append(lf)
            if len(ls) == 0: break
            tpv = ls.pop(0)
            if tpv != 'null':
                rt = TreeNode(int(tpv))
                tpn.right = rt
                ns.append(rt)
        return head







# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))

