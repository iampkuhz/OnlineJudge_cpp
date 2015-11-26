#
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l=0, r=len(height)-1;
        re = 0;
        while l < r:
            re = re if (l-r)*min(height[l],height[r]) < re else  (l-r)*min(height[l],height[r]);
            if height[l] < height[r]:
                l ++;
            else r --;
        return re;
                

        
