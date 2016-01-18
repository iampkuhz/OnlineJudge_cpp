#!/usr/bin/env python
# encoding: utf-8

"""
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
"""


class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        re, ls, sz = [], [], len(s)
        def dfs(ts):
            if (sz-ts) + len(ls) < 4 or (len(ls) + (sz-ts)/3) > 4: return
            if ts == sz:
                if len(ls) == 4:
                    re.append('.'.join(ls))
                return
            for i in range(1, 4):
                if i+ts <= sz and (int)(s[ts:ts+i]) < 256 and not (i>1 and s[ts] == '0'):
                    ls.append(s[ts:ts+i])
                    dfs(ts+i)
                    ls.pop()
        dfs(0)
        return re

s=Solution()
print s.restoreIpAddresses("25525511135")





