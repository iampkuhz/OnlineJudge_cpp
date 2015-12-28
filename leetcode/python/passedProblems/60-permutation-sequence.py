#!/usr/bin/env python
# encoding: utf-8

"""
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
"""


class Solution(object):
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        f = lambda x: x and x * f(x-1) or 1
        re = []
        ns = [i+1 for i in range(n)]
        def getN(nn, kk):
            if nn < 0:
                return
            ind = kk/f(nn)
            re.append(ns[ind])
            ns.pop(ind)
            getN(nn-1, kk- ind * f(nn))
        getN(n-1, (k-1) % f(n))
        return ''.join([str(i) for i in re])

s=Solution()
print s.getPermutation(3, 1)
print s.getPermutation(3, 2)
print s.getPermutation(3, 3)
print s.getPermutation(3, 4)
print s.getPermutation(3, 5)
print s.getPermutation(3, 6)
print s.getPermutation(3, 7)

