#!/usr/bin/env python
# encoding: utf-8

"""
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
"""


# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) < 1:
            return []
        intervals.sort(key=lambda x:(x.start, -x.end))
        re = []
        itv = intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i].start <= itv.end:
                itv.end = max(itv.end, intervals[i].end)
            else:
                re.append(itv)
                itv = intervals[i]
        re.append(itv)
        return re
