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
    sn=[]
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return [];
        self.sn = sorted(nums);
        #print 'sn:',self.sn
        re=[];
        for i in range(0, len(self.sn)-2):
            for j in range(i+1, len(self.sn)-1):
                k=self.findK(-self.sn[i]-self.sn[j], j+1, len(self.sn)-1);
                if k > 0:
                    if len(re)>0 and self.sn[i] == re[len(re)-1][0] and self.sn[j] == re[len(re)-1][1]:
                        continue;
                    re.append([self.sn[i],self.sn[j],self.sn[k]]);
                    #print i,j,k;
        return re;

    def findK(self, k, l, r):
        if l >= r:
            return l if l<=r and self.sn[l] == k else -1;
        m = (l+r)/2;
        if self.sn[m] == k:
            return m;
        elif self.sn[m] > k:
            return self.findK(k, l, m-1);
        else :
            return self.findK(k, m+1, r);
        
s=Solution();
print s.threeSum([-1,0,1,2,-1,-4]);

        
        
