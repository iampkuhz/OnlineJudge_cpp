#!/usr/bin/env python
# encoding: utf-8

"""
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
"""
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n=len(height);
        if n < 1:
            return 0;
        m=[height[0]]*n;
        for i in range(1,n):
            m[i] = max(m[i-1],height[i]);
        m[n-1]=height[n-1];
        for i in range(n-2,-1,-1):
            m[i] = min(m[i],max(m[i+1],height[i]));
        re=0;
        for i in range(1,n-1):
            re += (m[i]-height[i]);
        return re;

#class Solution(object):
#    def trap(self, height):
#        """
#        :type height: List[int]
#        :rtype: int
#        """
#        n=len(height);
#        lm,rm=[-1]* n,[n] * n;
#        for i in range(1, n):
#            j=i-1;
#            while lm[j]>=0:
#                j=lm[j];
#            lm[i] = j if j>=0 and height[j]>height[i] else -1;
#        for i in range(n-2, -1, -1):
#            j=i+1;
#            while rm[j]<n:
#                j=rm[j];
#            rm[i] = j if j<n and height[j]>height[i] else n;
#        re = 0;
#        for i in range(1, n-1):
#            if lm[i] >=0 and rm[i]<n:
#                re += min(height[rm[i]],height[lm[i]])-height[i];
#        return re;
#
s=Solution();
print s.trap([0,1,0,2,1,0,1,3,2,1,2,1]);
