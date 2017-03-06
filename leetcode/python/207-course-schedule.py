#!/usr/bin/env python
# encoding: utf-8


"""

There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
"""




# 5次过，算法本身没问题，都是写错了，prerequisite，dep（N）[ti],...

class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        # 找图中是否有环，两个表，一个记录依赖个数，一个记录依赖的点
        dep = {}
        depN = {}
        for p in prerequisites:
            if p[0] not in dep: dep[p[0]] = []; depN[p[0]] = 1
            else: depN[p[0]] += 1

            if p[1] not in dep: dep[p[1]] = [p[0]]; depN[p[1]] = 0
            else: dep[p[1]].append(p[0])
        # 每次找出depN最小的点更新
        ls = []
        for i in depN:
            if depN[i] == 0: ls.append(i)
        while len(ls) > 0:
            ti = ls.pop(0)
            if depN[ti] > 0: return False
            del depN[ti]
            for j in dep[ti]:
                depN[j] -= 1
                if depN[j] == 0: ls.append(j)
        return len(depN) <=  0
