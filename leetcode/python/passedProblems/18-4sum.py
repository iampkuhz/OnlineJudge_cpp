#-*-coding:utf-8-*-
"""

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
"""
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        re=[];
        nums.sort();
        for i in range(len(nums)-3):
            if i == 0 or nums[i] != nums[i-1]:
                for j in range(i+1, len(nums)-2):
                    if j == i+1 or nums[j] != nums[j-1]:
                        k = j+1; l = len(nums)-1;
                        while k < l :
                            sums = nums[k] + nums[l] + nums[i] + nums[j];
                            if sums == target:
                                re.append([nums[i],nums[j],nums[k],nums[l]]);
                                k += 1;
                                while k < l and nums[k] == nums[k-1]:
                                    k += 1;
                            elif sums > target:
                                l -= 1;
                            else:
                                k += 1;
        return re;

s=Solution();
print s.fourSum([1,0,-1,0,-2,2],0);

                
        
