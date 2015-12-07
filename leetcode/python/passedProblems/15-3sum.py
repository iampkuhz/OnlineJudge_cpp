#-*-coding:utf-8-*-
#Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
"""
Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
"""

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return [];
        re = []
        nums.sort();
        for i in range(len(nums)):
            if i == 0 or nums[i] > nums[i-1]:
                j = i+1; k = len(nums)-1;
                #print i, j,k;
                while j < k :
                    if nums[j] + nums[k] == -nums[i]:
                        re.append([nums[i], nums[j], nums[k]]);
                        j += 1;
                        while j < len(nums) and j < k and  nums[j] == nums[j-1]:
                            j += 1;
                    elif nums[j] + nums[k] < -nums[i]:
                        j += 1;
                    else:
                        k -= 1;
        return re;
                        

#class Solution(object):
#    sn=[]
#    def threeSum(self, nums):
#        """
#        :type nums: List[int]
#        :rtype: List[List[int]]
#        """
#        if len(nums) < 3:
#            return [];
#        self.sn = sorted(nums);
#        #print 'sn:',self.sn
#        re=[];
#        for i in range(0, len(self.sn)-2):
#            for j in range(i+1, len(self.sn)-1):
#                k=self.findK(-self.sn[i]-self.sn[j], j+1, len(self.sn)-1);
#                if k > 0:
#                    if len(re)>0 and self.sn[i] == re[len(re)-1][0] and self.sn[j] == re[len(re)-1][1]:
#                        continue;
#                    re.append([self.sn[i],self.sn[j],self.sn[k]]);
#                    #print i,j,k;
#        return re;
#
#    def findK(self, k, l, r):
#        if l >= r:
#            return l if l<=r and self.sn[l] == k else -1;
#        m = (l+r)/2;
#        if self.sn[m] == k:
#            return m;
#        elif self.sn[m] > k:
#            return self.findK(k, l, m-1);
#        else :
#            return self.findK(k, m+1, r);
        
s=Solution();
print s.threeSum([-1,0,1,2,-1,-4]);
print s.threeSum([13,5,-4,-9,1,-3,10,-7,7,3,1,-13,-11,7,-10,12,-15,13,5,-8,-11,-12,-15,-13,-3,-13,5,-4,6,1,-10,4,13,-7,3,-9,-3,-2,-1,12,9,-15,14,5,0,-10,-5,-8,-12,-15,-1,-8,11,-9,-14,-7,-6,7,-4,-15,-15,-7,-4,14,1,6,12,14,12,-11,11,-2,11,2,-12,-4,7,-2,-5,10,-9,10,9,-13,-14,11,-13,-13,3,-1,9,3,7,-9,-6,-14,4,-8,7,1,-12,-5,14,14,12,10,-12,-3,-7,-2,-8,-9,-7,9,-7,-13,5,-12,-11,-7,2,14,3,-14]);

        
        
