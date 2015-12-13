#-*-encoding:utf-8-*-
"""
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
"""
class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        ln = len(nums);p=ln-2;
        if ln < 2:
            return ;
        while p >= 0:
            if nums[p] < nums[p+1]:
                break;
            p -= 1;
        if p < 0:
            nums.reverse();
            return ;
        nums[p+1:]=nums[p+1:][::-1];
        #print 'nums1:', nums;
        pl=p+1; pr=ln-1;
        while pl < pr:
            if pl == pr-1:
                pl = pl if nums[pl] > nums[p] else pl+1;
                break;
            vm = nums[(pl+pr)/2];
            if vm > nums[p]:
                pr = (pl+pr)/2;
            else:
                pl = (pl+pr)/2+1;
        nums[pl],nums[p] = nums[p], nums[pl];
        #print 'nums2:', nums;
        return ;
        
s=Solution();
print s.nextPermutation([1,2,3]);
print s.nextPermutation([1,3,2]);
print s.nextPermutation([1]);
print s.nextPermutation([3,2,1]);
print s.nextPermutation([1,1,5]);
