#!/usr/bin/env python
# encoding: utf-8



"""
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
"""


# 5次过，几个细节:有空格、while lev>
class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 2个list：oper，num
        # *|/都是直接做，留下+|-第二轮由前往后做
        v = -1
        ops, num = [], []
        cnt = [0]
        def lev(c):
            return 1 if c in '+-' else 2
        def calc():
            n1, n2 = num.pop(), num.pop()
            op = ops.pop()
            re = n2-n1 if op == '-' else ( n2+n1 if op == '+' else (n2*n1 if op == '*' else n2/n1))
            num.append(re)
        for x in s:
            if x in '+-*/':
                if v >= 0: num.append(v); v = -1
                while len(ops) > 0 and lev(ops[-1]) >= lev(x):
                    calc()
                ops.append(x)
            elif x in '0123456789':
                v = v* 10 + int(x) if v >= 0 else int(x)
        num.append(v)
        while len(ops) > 0: calc()
        return num[0]



