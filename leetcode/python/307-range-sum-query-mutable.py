#!/usr/bin/env python
# encoding: utf-8


"""
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly."""

# 线段树

# 8次过：1.class不能内置（？） 2. l和left搞混 3.边界情况
class SegNode(object):
    def __init__(self, val, l, r):
        self.val = val
        self.l = l
        self.r = r
        self.left, self.right = None, None
class SegTree(object):
    def __init__(self, nums):
        self.nums = nums
        self.ln = len(nums)
        if self.ln < 1: return
        self.root = SegNode(sum(nums), 0, self.ln-1)
        ls = [self.root]
        while len(ls) > 0:
            tp = ls.pop()
            if tp.l == tp.r: continue
            m = (tp.l + tp.r)/2
            tp.left = SegNode(sum(nums[tp.l:m+1]), tp.l, m)
            tp.right = SegNode(sum(nums[m+1:tp.r+1]), m+1, tp.r)
            ls.append(tp.left)
            ls.append(tp.right)

    def update(self, ind, val):
        node = self.root
        dif = val - self.nums[ind]
        while ind >= node.l and ind <= node.r:
            node.val += dif
            if node.l == node.r: break
            m = (node.l + node.r)/2
            if m >= ind: node = node.left
            else: node = node.right
        self.nums[ind] = val

    def getSum(self, l, r):
        if self.ln < 1: return 0
        node = self.root
        return self.dfsSum(l,r,node)
    def dfsSum(self, l, r, node):
        if l <= node.l and r >= node.r: return node.val
        if r < node.l or l > node.r: return 0
        return self.dfsSum(l, r, node.left) + self.dfsSum(l, r, node.right)


class NumArray(object):
    def __init__(self, nums):
        self.st = SegTree(nums)

    def update(self, i, val):
        self.st.update(i, val)

    def sumRange(self, i, j):
        return self.st.getSum(i, j)
