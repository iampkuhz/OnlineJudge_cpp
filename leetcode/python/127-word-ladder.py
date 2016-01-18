#!/usr/bin/env python
# encoding: utf-8

"""
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
"""

# 看网上的答案，双向宽搜 470ms -> 356ms
# 1. 有条件的转换方向：每次选候选少的方向扩展 356ms -> 124ms
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        lword = len(beginWord)
        dis = [{beginWord}, {endWord}]
        disInt = [1,1]
        while len(dis[0])>0 and len(dis[1])>0:
            newDis = set()
            for wd in dis[0]:
                for i in range(lword):
                    for j in 'abcdefghijklmnopqrstuvwxyz':
                        nwd = wd[0:i] + j + wd[i+1:]
                        if nwd in dis[1]: return disInt[0] +disInt[1]
                        if nwd in wordList:
                            newDis.add(nwd)
                            wordList.remove(nwd)
            dis[0] = newDis
            disInt[0] += 1
            dis.reverse()
            disInt.reverse()
        return 0

# 宽搜,超时
# 看网上的答案，思路没问题，数据结构用复杂了
# 1. 不用next，用pop:过了。。。。特别慢，后5%
# 2.
# 3. remove adj: 740ms -> 670ms
# 4. 形成下一个字符串的时候右`"".join(x)`改成切片`x[0:i]+j+x[i+1:]`:670ms->472ms (72%)
# 5. 看分布还有明显更优的解法！！！
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        ls = [beginWord]
        lword = [len(beginWord)]
        import string
        thisDep=[[beginWord,1]]
        depth = 1
        while len(thisDep)>0:
            tp = thisDep.pop(0)
            depth = tp[1]+1
            wd = tp[0]
            for i in range(lword[0]):
                s=list(wd)
                ps = wd[0:i]; rs = wd[i+1:]
                for j in string.ascii_lowercase:
                    ns = ps + j + rs
                    if ns == endWord: return depth
                    if ns in wordList:
                        thisDep.append([ns,depth])
                        wordList.remove(ns) # 2, 804ms -> 740ms
        return 0


# 超时
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: Set[str]
        :rtype: int
        """
        # 每次变换一个字符，记录字典中的临近值
        ls = [beginWord]
        lword = [len(beginWord)]
        adj = {}
        re = [None]
        import string
        def find():
            for i in range(lword[0]):
                s=list(ls[-1])
                for j in string.ascii_lowercase:
                    s[i] = j
                    ns = "".join(s)
                    if ns == endWord:
                        re[0] = len(ls)+1 if re[0] == None else min(re[0], len(ls)+1)
                    elif ns in wordList and (not ns in ls) and (re[0] == None or re[0] > len(ls)):
                        ls.append(ns)
                        find()
                        ls.pop()
        find()
        return re[0]

s=Solution()
print s.ladderLength('a','c',['a','b','c'])
