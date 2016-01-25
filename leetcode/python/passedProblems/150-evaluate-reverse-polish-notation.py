#!/usr/bin/env python
# encoding: utf-8

"""
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
"""

# 网上答案,速度一般
class Solution(object):
    def evalRPN(self, tokens):
        stk = []
        opr = {'-': lambda x,y: x-y, '+': lambda x,y:x+y, '*': lambda x,y:x*y, '/': lambda x,y: x/y}
        for t in tokens:
            try:
                stk.append(float(t))
            except:
                stk.append(int(opr[t](stk.pop(-2), stk.pop(-1))))
        return int(stk[0])



# 时间效率很差，调了很多次，在/这里，系统要求 6/-132=0,13/5=2
class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        ns = []
        for x in tokens:
            if x in "+-*/":
                tp2 = ns.pop()
                tp1 = ns.pop()
                if x == '+': ns.append(tp1+tp2)
                if x == '-': ns.append(tp1-tp2)
                if x == '*': ns.append(tp1*tp2)
                if x == '/': ns.append(int((1.0*tp1/tp2)))
                #if x == '/': ns.append((tp1/tp2))
                print x, tp1, tp2, ns[-1]
            else: ns.append(int(x))
        return ns[0]
