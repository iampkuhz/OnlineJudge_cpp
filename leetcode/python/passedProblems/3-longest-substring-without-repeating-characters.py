# Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        cInd={}
        preInd = -1;
        if s is None or len(s) == 0:
            return 0;
        re = 0;
        for i in range(len(s)):
            if cInd.has_key(s[i]):
                preInd = max(preInd, cInd.get(s[i]));
            re = max(i-preInd, re);
            cInd[s[i]]=i;
        return re;

s= Solution();
print s.lengthOfLongestSubstring("abcabcbb");
print s.lengthOfLongestSubstring("bbbbb");
        
