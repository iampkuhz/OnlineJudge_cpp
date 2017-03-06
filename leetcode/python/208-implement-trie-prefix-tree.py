#!/usr/bin/env python
# encoding: utf-8


"""
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
"""


# 4次过，TrieNode写成TreeNode，忘了复制TrieNode代码，prefix写成word

class TrieNode(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.end = False
        self.char = None
        self.child = {}


class Trie(object):

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: void
        """
        t = self.root
        for x in word:
            if x not in t.child:
                c = TrieNode()
                c.char = x
                t.child[x] = c
                t = c
            else: t = t.child[x]
        t.end = True



    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        t = self.root
        for x in word:
            if x in t.child:
                t = t.child[x]
            else: return False
        return t.end


    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        t = self.root
        for x in prefix:
            if x in t.child:
                t = t.child[x]
            else: return False
        return True


# Your Trie object will be instantiated and called as such:
# trie = Trie()
# trie.insert("somestring")
# trie.search("key")
