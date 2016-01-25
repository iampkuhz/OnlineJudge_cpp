#!/usr/bin/env python
# encoding: utf-8

"""
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
"""


# 看答案，12次过

class Solution(object):
    def diffWaysToCompute(self, input):
        op = {'-':lambda x,y:x-y,
              '+':lambda x,y:x+y,
              '*':lambda x,y:x*y}

        def find(l, r):
            ans = []
            for i in range(l+1, r):
                if input[i] not in op: continue
                for x in find(l,i-1):
                    for y in find(i+1,r):
                        ans.append(op[input[i]](x,y))
            if len(ans) < 1 and l <= r:
                ans.append(int(input[l:r+1]))
            return ans
        if len(input) < 1: return []
        return find(0, len(input)-1)
