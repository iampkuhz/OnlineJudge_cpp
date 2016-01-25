#!/usr/bin/env python
# encoding: utf-8

"""


Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

"""


# 9次过，速度超级慢

class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 动规+剪枝，先减长的
        slen, re = [len(s)], [len(s)]
        p = [[-1 for i in range(slen[0])] for j in range(slen[0])]
        def isP(i, j):
            if i >= j: return True
            if p[i][j] >= 0: return True if p[i][j] > 0 else False
            p[i][j] = (1 if (s[i] == s[j] and isP(i+1, j-1)) else 0)
            return True if p[i][j] > 0 else False

        cnt = [-1 for i in range(slen[0])] + [0]
        def getCnt(ind):
            if ind == slen[0]: return 0
            if cnt[ind] > 0: return cnt[ind]
            remi = slen[0]
            for i in range(slen[0]-1, ind-1, -1):
                if isP(ind, i):
                    remi = min(remi, getCnt(i+1))
            cnt[ind] = remi+1
            return cnt[ind]
        return getCnt(0)-1

# 2次提交错误：range(slen), slen(0)
# 超时："fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi"
class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 动规+剪枝，先减长的
        slen, re = [len(s)], [len(s)]
        p = [[-1 for i in range(slen[0])] for j in range(slen[0])]
        def isP(i, j):
            if i >= j: return True
            if p[i][j] >= 0: return True if p[i][j] > 0 else False
            p[i][j] = (1 if (s[i] == s[j] and isP(i+1, j-1)) else 0)
            return True if p[i][j] > 0 else False

        cnt = [-1 for i in range(slen[0])]
        def getCnt(ind):
            if ind < 0 or ind >= slen[0]: return slen[0]
            if cnt[ind] > 0: return cnt[ind]
            remi = slen[0]
            for i in range(slen[0]-1, ind-1, -1):
                if isP(ind, i):
                    remi = min(remi, 1+getCnt(i+1))
            cnt[ind] = remi
            return cnt[ind]

        def dfs(tre, ind):
            #print tre, s[ind:], re[0]
            if ind == slen[0]:
                re[0] = min(re[0], tre)
                return
            if tre + (slen[0] - ind) >= re[0]: return
            if cnt[ind] < 0:
                getCnt(ind)
            re[0] = min(re[0], cnt[ind] + tre)

        dfs(0, 0)
        return re[0]

s=Solution()
print s.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi")
print s.minCut("amanaplanacanalpanama")
print s.minCut("aanaplanacanalpanama")
