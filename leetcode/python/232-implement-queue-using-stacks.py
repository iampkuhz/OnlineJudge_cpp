#!/usr/bin/env python
# encoding: utf-8



"""

Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
"""


# 2次过，速度差不多 40-44ms
class Queue(object):
    def __init__(self):
        self.ls = []

    def push(self, x):
        self.ls.append(x)

    def pop(self):
        return self.ls.pop()

    def peek(self):
        return self.ls[-1]

    def empty(self):
        return len(self.ls) == 0

# 3次过, 36-44ms
class Queue(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.ins, self.out = [], []


    def conv(self):
        k = len(self.ins)
        while k > 0:
            k -= 1
            self.out.append(self.ins.pop())
    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        self.ins.append(x)


    def pop(self):
        """
        :rtype: nothing
        """
        if len(self.out) == 0:self.conv()
        return self.out.pop()


    def peek(self):
        """
        :rtype: int
        """
        if len(self.out) == 0: self.conv()
        return self.out[-1]


    def empty(self):
        """
        :rtype: bool
        """
        return len(self.out) == 0 and len(self.ins) == 0

