#!/usr/bin/env python
# encoding: utf-8

"""
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
"""


# 3次过，时间一般，没有考虑全情况（对称情况）
class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        if len(version1) == 0:
            return 0 if len(version2) == 0 else -1
        if len(version2) == 0: return 1
        def s2i(vers):
            s = vers.split('.')
            return [int(x) for x in s]
        v1 = s2i(version1)
        v2 = s2i(version2)
        for i in range(len(v1)):
            if i >= len(v2):
                for j in range(i, len(v1)):
                    if v1[j] > 0: return 1
                return 0
            if v1[i] > v2[i] : return 1
            elif v1[i] < v2[i]: return -1
        for j in range(len(v1), len(v2)):
            if v2[j] > 0: return -1
        return 0

