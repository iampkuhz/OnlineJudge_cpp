#!/usr/bin/env python
# encoding: utf-8

"""
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
"""

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        re = []
        if len(intervals) < 1:
            return [newInterval]
        if newInterval.end < intervals[0].start:
            return [newInterval] + intervals
        elif newInterval.start > intervals[len(intervals)-1].end:
            return intervals + [newInterval]
        itv = newInterval
        insert = False
        for i in range(0, len(intervals)):
            if not insert and not( itv.start > intervals[i].end or itv.end < intervals[i].start):
                itv.start = min(itv.start, intervals[i].start)
                itv.end = max(itv.end, intervals[i].end)
            else:
                if not insert and itv.end < intervals[i].start:
                    re.append(itv)
                    insert = True
                re.append(intervals[i])
        if not insert:
            re.append(itv)
        return re


s=Solution()

