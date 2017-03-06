#!/usr/bin/env python
# encoding: utf-8



"""

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

"""


# 字符串查找、添加可以使用字典树Trie
# 4次过，忘写返回值，判断条件少node.end

class TrieNode(object):
    def __init__(self):
        self.val = None
        self.end = False
        self.child = {}

class WordDictionary(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.root = TrieNode()


    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        t =self.root
        for x in word:
            if x not in t.child:
                t.child[x] = TrieNode()
                t = t.child[x]
                t.char = x
            else: t = t.child[x]
        t.end = True


    def search(self, word):
        """
        Returns if the word is in the data structure. A word could
        contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        def inT(node, i):
            if i >= len(word): return True if node.end else False
            if word[i] in node.child:
                return inT(node.child[word[i]], i+1)
            elif word[i] == '.':
                for sn in node.child:
                    if inT(node.child[sn], i+1): return True
            return False
        return inT(self.root, 0)



# Your WordDictionary object will be instantiated and called as such:
# wordDictionary = WordDictionary()
# wordDictionary.addWord("word")
# wordDictionary.search("pattern")
