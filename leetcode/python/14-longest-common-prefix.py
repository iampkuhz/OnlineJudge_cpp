#Write a function to find the longest common prefix string amongst an array of strings.
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) < 1:
            return "";
        elif len(strs) == 1:
            return strs[0];
        s1 = self.longestCommonPrefix(strs[0:len(strs)/2]);
        s2 = self.longestCommonPrefix(strs[len(strs)/2:]);
        #print 's1:', s1;
        #print 's2:', s2;
        pt = 0;
        for i in range(len(s1)):
            #print 'i:',i
            if i >= len(s2) or s1[i] != s2[i]:
                #print i, len(s2), s1[i], s2[i]
                break;
            pt = i+1;
        return s1[0:pt];
        
s=Solution();
print s.longestCommonPrefix(['c','c']);

