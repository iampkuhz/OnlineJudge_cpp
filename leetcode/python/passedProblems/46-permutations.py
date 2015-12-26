#!/usr/bin/env python
# encoding: utf-8

"""

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

"""
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n=sorted(nums);
        re=[]
        def nextP(nn):
            re.append(nn[:]);
            # 从后往前找第一个非增
            j=len(nn)-2;
            while j >= 0 and nn[j]>nn[j+1]:
                j-=1;
            if j < 0: return;
            # 交换
            k=j+1;
            while k+1 < len(nn) and nn[k+1]>nn[j]:
                k+=1;
            nn[k],nn[j]=nn[j],nn[k];
            # 将后边的递增序列反序
            nn=nn[0:j+1]+nn[-1:j:-1]
            #print 'nn:',nn
            nextP(nn);
        nextP(n);
        return re;


s=Solution();
print s.permute([1,2,3]);





