# There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        l1 = len(nums1)
        l2 = len(nums2)
        ak = self.findK(nums1, nums2, (l1+l2+2)/2);
        ak1 = self.findK(nums1, nums2, (l1+l2+1)/2);
#        print ak , ".", ak1;
        return (0.0 + ak + ak1)/2;
    
    def findK(self, nums1, nums2, k):
#        print nums1, ".", nums2, ".", k;
        l1 = len(nums1);
        l2 = len(nums2);
        if l1 == 0:
            return nums2[k-1];
        elif l2 == 0:
            return nums1[k-1];
        if k == 1:
            return min(nums1[0], nums2[0]);
        p1 = max(0, min(l1- 1, (k-2)/2));
        p2 = k - p1 - 2;
        if(p2 > len(nums2)-1):
            p2 = len(nums2)-1;
            p1 = k - p2 - 2;
        if nums1[p1] > nums2[p2] :
            return self.findK(nums1[0:p1+1], nums2[p2+1:], k - p2 -1);
        elif  nums1[p1] == nums2[p2]:
            return nums1[p1];
        else:
            return self.findK(nums1[p1+1:], nums2[0:p2+1], k - p1 - 1);
        
        
s = Solution();
print s.findMedianSortedArrays([1,2,3,5,7,23,25],[2,4,5,6,7,8,9]);
