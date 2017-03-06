#!/usr/bin/env python
# encoding: utf-8


"""
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
"""


# 10次过，看答案
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        if t < 0 or k <= 0: return False
        t += 1
        nl = len(nums)
        bk = {}
        for i in range(nl):
            if i>k: del bk[nums[i-k-1]/t]
            tbk = nums[i]/t
            if tbk in bk: return True
            if tbk - 1 in bk and abs(bk[tbk-1]-nums[i])<t : return True
            if tbk + 1 in bk and abs(bk[tbk+1]-nums[i])<t : return True
            bk[tbk] = nums[i]
        return False

# 超时
class Solution(object):
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        ps={}
        nl = len(nums)
        for i in range(nl):
            if nums[i] not in ps: ps[nums[i]] = [i]
            else: ps[nums[i]].append(i)
        p = []
        for x in ps:
            p.append([x, ps[x]])
        def mcmp(p1, p2):
            return 1 if p1[0] > p2[0] else -1
        p.sort(cmp=mcmp)
        for i in range(len(p)):
            for j in range(0, len(p[i][1])-1):
                if p[i][1][j+1] - p[i][1][j]  <= k: return True
            for l in range(i+1, len(p)):
                if p[l][0] - p[i][0] > t: break
                for ii in range(0, len(p[i][1])):
                    for ll in range(0, len(p[l][1])):
                        if abs(p[l][1][ll] - p[i][1][ii]) <= t: return True
        return False





