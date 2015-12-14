#-*-coding:utf-8-*-
"""

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
"""

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        t, l,r,m=target, 0, len(nums)-1,0;
        while l+1 < r:
            m = (l+r)/2;
            if nums[m] == t:
                return m;
            elif nums[m] > t:
                if nums[m] < nums[l]:
                    r = m-1;
                else:
                    if nums[l] > t:
                        l = m+1;
                    else:
                        r = m-1;
            else:
                if nums[m] > nums[l]:
                    l = m+1;
                else:
                    if nums[r] >= t:
                        l = m+1;
                    else:
                        r = m-1;
        #print 'l:', l, nums[l] , 'r:', r, nums[r]
        #print 'nums:', nums, 't:',t
        return l if nums[l] == t else r if nums[r] == t else -1;
        

# [5,1,2],5过不了,而且完全没必要专门建二分查找函数bs
#class Solution(object):
#    def search(self, nums, target):
#        """
#        :type nums: List[int]
#        :type target: int
#        :rtype: int
#        """
#        return self.find(nums, 0, len(nums)-1,target);
#
#    def find(self, nums, a, b, t):
#        if a+1>=b:
#            return a if nums[a] == t else b if nums[b] == t else -1;
#        if nums[a] < nums[b]:
#            return self.bs(nums, a, b ,t);
#        nm = nums[(a+b)/2];
#        m = (a+b)/2;
#        if nm == t:
#            return m;
#        elif nm > t:
#            return self.find(nums, m, b,t) if nums[a] > t else self.bs(nums, a, m-1, t);
#        return self.find(nums, m+1, b, t);
#
#    def bs(self, nums, a, b, t):
#        if a + 1 >= b:
#            return a if nums[a] == t else b if nums[b] == t else -1;
#        m = (a+b)/2;
#        return m if nums[m] == t else self.bs(nums, a, m-1, t) if nums[m] > t else self.bs(nums, m+1, b, t);

s=Solution();
print s.search([4,5,6,7,0,1,2],1);


        
