#!/usr/bin/env python
# encoding: utf-8

"""
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
"""

class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        fds = path.split('/')
        re = []
        for i in range(len(fds)):
            if len(fds[i]) == 0 or fds[i] == '.':
                continue
            if fds[i] == '..' and len(re) > 0:
                re.pop()
            elif fds[i] != '..': re.append(fds[i])
        return '/' + '/'.join(re)

s=Solution()
print s.simplifyPath("/home/")
print s.simplifyPath("/home//foo/")
print s.simplifyPath("/a/./b/../../c/")
print s.simplifyPath("/../")
