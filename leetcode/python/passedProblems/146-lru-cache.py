#!/usr/bin/env python
# encoding: utf-8

"""
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
"""

# 4次过，开始没理解题意，get也算使用，速度不快，看一下别人的代码
class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.ls = []
        self.k2v = {}
        self.cap = capacity


    def get(self, key):
        """
        :rtype: int
        """
        if key in self.k2v:
            self.ls.remove(key)
            self.ls.append(key)
            return self.k2v[key]
        return -1


    def set(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: nothing
        """
        if key in self.k2v:
            self.ls.remove(key)
        elif len(self.ls) >= self.cap:
            del self.k2v[self.ls.pop(0)]
        self.k2v[key] = value
        self.ls.append(key)
