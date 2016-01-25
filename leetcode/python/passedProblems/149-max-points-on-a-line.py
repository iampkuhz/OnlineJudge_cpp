#!/usr/bin/env python
# encoding: utf-8


"""
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
"""

# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b




# 时间效率一般，9次过，几个细节都没考虑到, j 循环改成range(i+1,slen): 108ms -> 76ms
class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[Point]
        :rtype: int
        """
        slen = len(points)
        if slen < 2: return slen

        re = 0
        for i in range(slen):
            base = 1
            vert = 0
            dis = []
            for j in range(slen):
                if j == i: continue
                if points[j].x == points[i].x:
                    if points[j].y == points[i].y:
                        base += 1; continue
                    vert += 1; continue
                dis.append(1.0*(points[j].y-points[i].y)/(points[j].x-points[i].x))
            dis.sort()
            if len(dis) < 1:
                re = max(re, vert + base)
                continue
            last = dis[0]; line = 1; maxl = vert
            for k in range(1, len(dis)):
                if dis[k] - last < 1e-7: line += 1
                else:
                    maxl = max(maxl, line)
                    line = 1
                    last = dis[k]
            maxl = max(maxl, line)
            re = max(re, maxl + base)
        return re



