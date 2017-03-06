#!/usr/bin/env python
# encoding: utf-8


"""
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
"""

# 最大最小堆,看答案, 17次过
import heapq
class MedianFinder:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.maxH = []
        self.minH = []


    def addNum(self, num):
        """
        Adds a num into the data structure.
        :type num: int
        :rtype: void
        """
        if len(self.maxH) == len(self.minH):
            heapq.heappush(self.minH, num)
            heapq.heappush(self.maxH, -heapq.heappop(self.minH))
        else:
            heapq.heappush(self.maxH, -num)
            heapq.heappush(self.minH, -heapq.heappop(self.maxH))
    def findMedian(self):
        """
        Returns the median of current data stream
        :rtype: float
        """
        if len(self.maxH) == len(self.minH):
            return (0.0 - self.maxH[0] + self.minH[0]) /2
        return -self.maxH[0]



# Your MedianFinder object will be instantiated and called as such:
# mf = MedianFinder()
# mf.addNum(1)
# mf.findMedian()

# 大小两堆,超时
class MedianFinder:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.ls = []
        self.rs = []
        self.val = None
        self.empty = True


    def addNum(self, num):
        """
        Adds a num into the data structure.
        :type num: int
        :rtype: void
        """
        if self.val == None:
            if self.empty or (num >= self.ls[-1] and self.rs[-1] >= num):
                self.val = num
            elif num < self.ls[-1]:
                self.val = self.ls[-1]
                self.ls[-1] = num
            else:
                self.val = self.rs[-1]
                self.rs[-1] = num
        else:# 本来是奇数个
            if num >= self.val: # num放右边
                self.rs.append(num)
                self.ls.append(self.val)
                m = 0
                for i in range(1, len(self.rs)):
                    if self.rs[i] < self.rs[m]: m = i
                self.rs[-1] = self.rs[m]
                self.rs[m] = num
            else:
                self.ls.append(num)
                self.rs.append(self.val)
                m = 0
                for i in range(1, len(self.ls)):
                    if self.ls[i] > self.ls[m]: m = i
                self.ls[-1] = self.ls[m]
                self.ls[m] = num
            self.val == None
        self.empty = False

    def findMedian(self):
        """
        Returns the median of current data stream
        :rtype: float
        """
        if None != self.val: return self.val
        return (0.0 + self.ls[-1] + self.rs[-1]) /2


# Your MedianFinder object will be instantiated and called as such:
# mf = MedianFinder()
# mf.addNum(1)
# mf.findMedian()
