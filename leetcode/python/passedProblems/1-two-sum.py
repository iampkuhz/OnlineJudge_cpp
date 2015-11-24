class Solution(object/:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sortNums=sorted(nums);
        pl = 0;
        pr = len(nums) - 1;
        while (pl < pr):
            sum = sortNums[pl] + sortNums[pr];
            if sum == target:
                break;
            elif sum > target:
                pr -= 1;
            else:
                pl += 1;
        
        if pl == pr:
            return -1,-1;
        else:
            pos1 = nums.index(sortNums[pl]) + 1;
            pos2 = nums.index(sortNums[pr]) + 1;
            if pos1 == pos2:
                pos2 = nums[pos1:].index(sortNums[pr]) + 1 + pos1;
            return min(pos1, pos2), max(pos1, pos2);

        
