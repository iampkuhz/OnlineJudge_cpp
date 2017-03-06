#!/usr/bin/env python
# encoding: utf-8


"""
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]
"""

# 6次过，非常慢1380ms，3.7%
class node(object):
    def __init__(self, val):
        self.val = val
        self.nb = set()

class Solution(object):
    def findMinHeightTrees(self, n, edges):
        #init
        nodes = {i:node(i) for i in range(n)}
        for p in edges:
            nodes[p[0]].nb.add(p[1])
            nodes[p[1]].nb.add(p[0])
        while True:
            if len(nodes) == 1:
                return [i for i in nodes]
            dnds = []
            intn = False
            for i in nodes:
                lnn = len(nodes[i].nb)
                if lnn == 1:
                    dnds.append(i)
                else: intn = True
            if not intn: return [i for i in nodes]
            for i in dnds:
                for nb in nodes[i].nb:
                    nodes[nb].nb.remove(i)
                del nodes[i]






# 5000个点超时, 直线的情况，每次只能删2个点，递归次数过多
class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        # 所有点安装连通度排序，如果没有连通度大于一的点，则所有剩下的连通度为1的点都可以是根节点
        edgeCnt = [[i, 0] for i in range(n)]
        for p in edges:
            edgeCnt[p[0]][1] += 1
            edgeCnt[p[1]][1] += 1
        edgeCnt.sort(key=lambda x:x[1])
        while edgeCnt[-1][1] > 1:
            print len(edgeCnt), edgeCnt
            ind = 0
            while ind < len(edgeCnt) and edgeCnt[ind][1] == 1: ind += 1
            rmN = set(p[0] for p in edgeCnt[0:ind])
            nEdgeCnt = {}
            for i in range(ind, len(edgeCnt)):
                nEdgeCnt[edgeCnt[i][0]] = edgeCnt[i][1]
            nEdges = []
            for p in edges:
                if p[0] in rmN: nEdgeCnt[p[1]] -= 1
                elif p[1] in rmN: nEdgeCnt[p[0]] -= 1
                else: nEdges.append(p)
            edges = nEdges
            edgeCnt = [[p,nEdgeCnt[p]] for p in nEdgeCnt]
            edgeCnt.sort(key=lambda x:x[1])
        return [p[0] for p in edgeCnt]




