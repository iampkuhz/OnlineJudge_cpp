"""
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
"""
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) < 3:
            return 0;
        nums.sort();
        re = nums[0] + nums[1] + nums[2];
        for i in range(len(nums)-2):
            j = i + 1; k = len(nums)-1;
            while j < k:
                sum = nums[i] + nums[j] + nums[k];
                if sum == target :
                    return sum;
                re = sum if abs(sum-target) < abs(re-target) else re;
                if sum > target:
                    k -= 1;
                else:
                    j += 1;
        return re;

s = Solution();
print s.threeSumClosest([-1,2,1,-4],1);

        
