#!/usr/bin/env python
# encoding: utf-8

"""
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
"""



# 提交10次过，624ms，一般方法中比较好的，还有非常明显的快方法
class Solution(object):
    def findLadders(self, beginWord, endWord, wordlist):
        """
        :type beginWord: str
        :type endWord: str
        :type wordlist: Set[str]
        :rtype: List[List[int]]
        """
        # 单源最短路径，宽搜，记录前一个节点
        lwd = len(beginWord)
        pre={}
        levelWords=[beginWord]
        rel = []
        def fill(wd, ls):
            if wd == beginWord:
                rel.append(ls[:] + [beginWord])
                return
            for pwd in pre[wd]:
                fill(pwd, ls[:]+[wd])

        while len(levelWords)>0:
            nLWords=[]
            tpre={}
            re = None
            for wd in levelWords:
                for i in range(lwd):
                    for j in 'abcdefghijklmnopqrstuvwxyz':
                        nwd = wd[0:i] + j + wd[i+1:]
                        if nwd == endWord:
                            re = nwd
                        if nwd in wordlist:
                            if nwd not in tpre: tpre[nwd]=[]
                            tpre[nwd].append(wd)
            pre.update(tpre)
            for wd in tpre:
                wordlist.remove(wd)
                nLWords.append(wd)
            if re != None:
                fill(re, [])
                for r in rel:
                    r.reverse()
                return rel
            levelWords=nLWords
        return []

