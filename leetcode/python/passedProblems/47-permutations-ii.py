#!/usr/bin/env python
# encoding: utf-8

"""
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
"""


class Solution(object):

    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        #print nums
        re=[]

        def nextP(nn):
            #print 'nn:', nn
            re.append(nn[:])
            # 从后往前找第一个非增数
            j=len(nn)-2
            while j >=0 and nn[j]>=nn[j+1]:
                j-=1
            if j < 0 : return
            k=j+1
            while k+1 < len(nn) and nn[k+1]>nn[j]:
                k+=1
            # 交换
            nn[j], nn[k]=nn[k], nn[j]
            # 后一半反序
            nn= nn[0:j + 1] + nn[len(nn) - 1:j: -1]
            nextP(nn)
        nextP(nums)
        return re

s=Solution()
print s.permuteUnique([1,2,3])
print s.permuteUnique([1,1,3])

