#!/usr/bin/env python
# encoding: utf-8

"""
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.

"""
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        lt=[[s,''.join(sorted(s))] for s in strs];
        #print lt
        lt.sort(key=lambda x:x[1])
        #print lt;
        re=[];
        j = 0
        while j < len(lt):
            k=lt[j][1]
            l=[lt[j][0]]
            while j+1 < len(lt) and lt[j][1]==lt[j+1][1]:
                l.append(lt[j+1][0]);
                j+=1;
            l = sorted(l);
            re.append(l);
            j += 1
        return re;

s=Solution();
print s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])


