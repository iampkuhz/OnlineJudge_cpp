#!/usr/bin/env python
# encoding: utf-8

"""

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

"""


class Solution(object):
    def addBinary(self, a, b):
        return bin(int('0b' + a, 2) + int('0b' + b, 2))[2:]

#class Solution(object):
#    def addBinary(self, a, b):
#        """
#        :type a: str
#        :type b: str
#        :rtype: str
#        """
#        s1, s2 = len(a), len(b)
#        i1, i2 = s1-1, s2-1
#        add = 0
#        re = ""
#        while i1 >= 0 and i2 >= 0:
#            sums = add + int(a[i1]) + int(b[i2])
#            re = str(sums % 2) + re
#            add = sums /2
#            i1, i2 = i1-1, i2-1
#        while i1 >= 0:
#            sums = add + int(a[i1])
#            re = str(sums % 2) + re
#            add = sums / 2
#            i1 -= 1
#        while i2 >= 0:
#            sums = add + int(b[i2])
#            re = str(sums % 2) + re
#            add = sums / 2
#            i2 -= 1
#        if add > 0:
#            re = '1' + re
#        return re


s=Solution()
print s.addBinary("1","111")
