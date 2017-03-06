#!/usr/bin/env python
# encoding: utf-8

"""
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
"""


# 1. 超时
class MinStack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.ls = []
        self.minInd = -1


    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        if len(self.ls) > 0:
            if self.min >= 0 and x < self.ls[self.minInd]:
                self.minInd = len(self.ls)
        else: self.minInd = 0
        self.ls.append(x)


    def pop(self):
        """
        :rtype: nothing
        """
        self.minInd -= 1
        return self.ls.pop()


    def top(self):
        """
        :rtype: int
        """
        return self.ls[-1]


    def getMin(self):
        """
        :rtype: int
        """
        if self.minInd < 0:
            self.minInd = 0
            for i in range(1, len(self.ls)):
                if self.ls[i] < self.ls[self.minInd]:
                    self.minInd = i
        return self.ls[self.minInd]

