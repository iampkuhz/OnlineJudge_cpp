#!/usr/bin/env python
# encoding: utf-8


"""
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?
"""

# 4次过，dfs忘记返回True，记得判断'090009'
class Solution(object):
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        # 前两个最多2/3n长
        def dfs(a, b, ind):
            if ind >= len(num): return True
            n = a+b
            nl = len(str(n))
            if nl > len(num) - ind: return False
            if str(n) != num[ind:ind+nl]: return False
            return dfs(b, n, ind + nl)
        nl = len(num)
        if nl < 3: return False
        for i in range(1, nl/2+1):
            if i > 1 and num[0] == '0': break
            for j in range(1, 2*nl/3-i+1):
                if j > 1 and num[i] == '0': break
                if dfs(int(num[0:i]), int(num[i:i+j]), i+j):
                    return True
        return False


