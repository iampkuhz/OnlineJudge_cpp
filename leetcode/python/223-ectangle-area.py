#!/usr/bin/env python
# encoding: utf-8


"""
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
"""


# 3次过，求得是覆盖面积，不是交集
class Solution(object):
    def computeArea(self, A, B, C, D, E, F, G, H):
        """
        :type A: int
        :type B: int
        :type C: int
        :type D: int
        :type E: int
        :type F: int
        :type G: int
        :type H: int
        :rtype: int
        """
        def overlap(a,c,e,g):
            if a > e: return overlap(e,g,a,c)
            if e >= c: return 0
            return c-e if g >= c else g-e
        def sq(a,b,c,d):
            return (d-b)*(c-a)

        return -overlap(A,C,E,G) * overlap(B,D,F,H) + sq(A,B,C,D) + sq(E,F,G,H)
