#!/usr/bin/env python
# encoding: utf-8


"""
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"


"""

# 和stack方法类似，在最后一个字符之前
# 看答案1次过，64ms
class Solution(object):
    def removeDuplicateLetters(self, s):
        lastApp = {c:i for i,c in enumerate(s)}
        inRes = 0
        re = []
        for i in range(len(s)):
            ind = ord(s[i]) - 97
            mask = 1 << ind
            if not inRes & mask:
                while re and re[-1] > s[i] and lastApp[re[-1]] > i:
                    inRes ^= 1 << (ord(re.pop())-97)
                re.append(s[i])
                inRes ^= 1 << ind
        return ''.join(re)

# 贪心，看到答案, 5次过，56ms
class Solution(object):
    def removeDuplicateLetters(self, s):
        cnt, ans, vis = [0]*26, [], [False] * 26
        for c in s:
            cnt[ord(c)-97] += 1
        for c in s:
            ind = ord(c)-97
            if vis[ind]:
                cnt[ind] -= 1
                continue
            while len(ans) > 0 and ans[-1] > c and cnt[ord(ans[-1])-97] > 0:
                vis[ord(ans.pop())-97] = False
            vis[ind] = True
            ans.append(c)
            cnt[ind] -= 1
        return ''.join(ans)


# 递归超时,一个非常长的字符串超时
class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        dup = [-1] * 27
        for i in range(0, len(s)):
            ind = ord(s[i]) - ord('a')
            if dup[ind] >= 0:
                if s[dup[ind]] < s[dup[ind]+1]:
                    return self.removeDuplicateLetters(s[0:i] + s[i+1:])
                else: return self.removeDuplicateLetters(s[0:dup[ind]] + s[dup[ind]+1:])
            else: dup[ind] = i
        return s


