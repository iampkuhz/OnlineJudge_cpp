#!/usr/bin/env python
# encoding: utf-8

"""

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
"""


class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        re = []
        i = 0
        while i < len(words):
            llen, j, wc = len(words[i]), i, len(words[i])
            while j+1 < len(words) and llen + len(words[j+1]) + 1 <= maxWidth:
                j += 1; llen += len(words[j]) + 1; wc += len(words[j])
            line = words[i]
            if j == i:
                re.append(line + ' '*(maxWidth - len(words[i])))
                i += 1
                continue
            wc = maxWidth - wc
            spLen = wc/(j-i)
            kb = wc - spLen*(j-i)
            for k in range(i+1, j +1):
                l = ' ' if j == len(words)-1 else ' '*spLen if k-i > kb else ' '*(spLen+1)
                line += l + words[k]
            if j == len(words)-1:
                line += ' '*(maxWidth - len(line))
            re.append(line)
            i = j + 1
        return re


s = Solution()
print s.fullJustify(["This", "is", "an", "example", "of", "text", "justification."], 16)
print s.fullJustify(["a","b","c","d","e"],3)
