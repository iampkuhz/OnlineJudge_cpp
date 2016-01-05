#!/usr/bin/env python
# encoding: utf-8

"""

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

"""


class Solution(object):
    def largestRectangleArea(self, height):
        if not height: return 0
        stk = []
        re = 0
        height.append(0)
        for k in range(len(height)):
            while (stk and height[k] <= height[stk[-1]]):
                re = max(re, height[stk.pop()] * (k if not stk else k-stk[-1]-1))
            stk.append(k)
        return re


#class Solution(object):
#    def largestRectangleArea(self, height):
#        """
#        :type height: List[int]
#        :rtype: int
#        """
#        # 找左、右比他大的边界，然后算大小
#        sz = len(height)
#        l, r = [i for i in range(sz)], [i for i in range(sz)]
#        for i in range(1, sz):
#            j = i-1
#            while j >= 0 and height[j] >= height[i]:
#                while j >= 0 and l[j] < j:
#                    j = l[j]
#                j -= 1
#            l[i] = j+1
#        for i in range(sz-2, -1, -1):
#            j = i + 1
#            while j < sz and height[j] >= height[i]:
#                while j < sz and r[j] > j:
#                    j = r[j]
#                j += 1
#            r[i] = j-1
#        re = 0
#        for i in range(sz):
#            re = re if (r[i]-l[i]+1)*height[i] <= re else (r[i]-l[i]+1)*height[i]
#        return re


s=Solution()
print s.largestRectangleArea([2,1,2])
