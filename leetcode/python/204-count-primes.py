#!/usr/bin/env python
# encoding: utf-8


"""
Count the number of prime numbers less than a non-negative number, n.
"""

# 看答案，貌似还有更好的方法 55%
# http://stackoverflow.com/questions/2068372/fastest-way-to-list-all-primes-below-n
class Solution(object):
    def countPrimes(self, n):
        isp = [True] * max(n, 2)
        isp[0], isp[1] = False, False
        p = 2
        while p * p < n:
            if isp[p]:
                t = p * p
                while t < n:
                    isp[t] = False
                    t += p
            p += 1
        return sum(isp)


# math.sqrt(x)不确定用对了
# 49978超
# gap 2 + for j in p, 999983超时
# 改成6n+1，6n+5还是999983超时

class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2: return 0
        if n < 6: return 3 if n >4 else (2 if n>2 else 1)
        p = [2,3,5]
        import math
        def isp(i):
            isp = True
            bd = math.sqrt(i)
            for j in p:
                if j > bd: break
                if i % j == 0:
                    isp = False
                    break
            if isp: p.append(i);print i

        for i in range(7, n, 6):
            isp(i)
            isp(i+4)

        return len(p)

s=Solution()
#print s.countPrimes(1000000)
print s.countPrimes(1000)
