#!/usr/bin/env python
# encoding: utf-8

"""
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
"""


# Definition for a undirected graph node
# class UndirectedGraphNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

# 速度一般，5次过，全部是小错误：UndirectedGraphNode拼错、ls=o2n.append(),.label写成.val
class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: UndirectedGraphNode
        :rtype: UndirectedGraphNode
        """
        # dict：old->new,初始点出发，深搜
        if node == None: return None
        o2n = {}
        ls = [[node, UndirectedGraphNode(node.label)]]
        while len(ls) > 0:
            tp = ls.pop(0)
            if o2n.has_key(tp[0]): continue
            o2n[tp[0]] = tp[1]
            for nb in tp[0].neighbors:
                newNb = o2n[nb] if o2n.has_key(nb) else UndirectedGraphNode(nb.label)
                tp[1].neighbors.append(newNb)
                if nb not in o2n:
                    ls.append([nb, newNb])
        return o2n[node]



