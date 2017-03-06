#!/usr/bin/env python
# encoding: utf-8


"""
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]

"""

# 7次过：重复的情况，剪枝，加上/不加上，两种情况分开考虑
class Solution(object):
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        re = set()
        maxRe = [0]
        lastForm = [set() for i in range(len(s))]
        def dfs(form, ind, cntl, cntr):
            if ind >= len(s):
                if cntl == cntr:
                    re.add(form)
                    maxRe[0] = max(maxRe[0], len(form))
                return
            if len(s) - ind + len(form) < maxRe[0]: return
            if form in lastForm[i]: return
            if s[ind] == '(':
                dfs(form + '(', ind+1, cntl+1, cntr)
                dfs(form, ind+1, cntl, cntr)
            elif s[ind] == ')':
                if cntl > cntr:
                    dfs(form + ')', ind+1, cntl, cntr+1)
                dfs(form, ind+1, cntl, cntr)
            else:
                dfs(form + s[ind], ind+1, cntl, cntr)
            lastForm[i].add(form)
        dfs('', 0, 0,0)
        return [x for x in re if len(x) == maxRe[0]]




