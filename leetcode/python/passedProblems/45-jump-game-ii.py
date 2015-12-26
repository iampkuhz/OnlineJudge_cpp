#!/usr/bin/env python
# encoding: utf-8

"""
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
"""

class Solution(object):
    def jump(self, nums):
        thisMax=0;
        nextMax=nums[0];
        i = 0;re=0;
        while i < len(nums):
            if i <= thisMax:
                nextMax=max(nextMax,i+nums[i])
                i+=1;
            else:
                thisMax=nextMax;
                re += 1;
        return re;



#class Solution(object):
#    def jump(self, nums):
#        """
#        :type nums: List[int]
#        :rtype: int
#        """
#        import Queue;
#        qu=Queue.Queue();
#        qu.put([0,0]);
#        m=[-1 for i in range(len(nums))];
#        inQ=[False for i in range(len(nums))];
#        inQ[0]= True;
#
#        while not qu.empty():
#            top=qu.get();
#            if m[top[0]]>=0:continue;
#            m[top[0]]=top[1];
#            if(top[0]==len(nums)-1):
#                break;
#            #print top[0];
#            i=top[0];
#            for j in range(i+nums[i], i, -1):
#                if j < len(nums) and m[j]<0 and not inQ[j]:
#                    qu.put([j,top[1]+1]);
#                    inQ[j]=True;
#                elif j < len(nums) and m[j]>=0: break;
#        #print m;
#        return m[len(nums)-1];



s=Solution();
#print s.jump([2,3,1,1,4]);
print s.jump([10,9,8,7,6,5,4,3,2,1,1,0]);
print s.jump([1,2,0,1]);
