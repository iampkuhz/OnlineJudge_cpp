#!/usr/bin/env python
# encoding: utf-8


"""
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
"""

# 8次过，考虑的不清楚
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 1. str => opers + nums
        # 1.1 数字：做一次操作；+/-/(：不做；）：一直做到（
        v = -1
        ops, num = [], []
        for x in s:
            if x in ')+-':
                if v >= 0:
                    num.append(v)
                    v = -1
                if len(ops) > 0:
                    op = ops.pop()
                    if op == '(':
                        if x != ')':
                            ops.append(x);
                        continue
                    n1, n2 = num.pop(), num.pop()
                    num.append(n2 - n1 if op == '-' else n1 + n2)
                    if x == ')' and len(ops) > 0 and ops[-1] == '(': ops.pop()
            if x in '+-(':
                ops.append(x)

            elif x in '0123456789':
                v = v*10 + int(x) if v >= 0 else int(x)
        if v >= 0:
            num.append(v)
        if len(ops) > 0:
            return num[0] - num[1] if ops[0] == '-' else num[1] + num[0]
        return num[0]


