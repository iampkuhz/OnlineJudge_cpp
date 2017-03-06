#!/usr/bin/env python
# encoding: utf-8


"""
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
"""



# 3次过，没有把所有点初始化加入depN
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        n, pr = numCourses, prerequisites
        depN, chg = {}, {}
        for i in range(n):
            depN[i] = 0
        for p in pr:
            depN[p[0]] += 1
            if p[1] not in chg: chg[p[1]] = [p[0]]
            else: chg[p[1]].append(p[0])
        ls = []
        for i in depN:
            if depN[i] == 0: ls.append(i)
        re = []
        while len(ls) > 0:
            tp = ls.pop(0)
            re.append(tp)
            del depN[tp]
            if tp not in chg: continue
            for j in chg[tp]:
                depN[j] -= 1
                if depN[j] == 0: ls.append(j)
        return re if len(re) == n else []



