"""
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
"""
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        if len(needle) < 1:
            return 0;
        if len(haystack) < 1:
            return -1;
        # KMP
        bef=[-1];
        for i in range(1, len(needle)):
            befV = bef[i-1];
            while True:
                if needle[befV+1] == needle[i]:
                    bef.append(befV+1);
                    break;
                if befV >= 0:
                    befV = bef[befV];
                else:
                    bef.append(-1);
                    break;
        i1=0;i2=0;
        while i1 < len(haystack) and i2 < len(needle):
            if haystack[i1] == needle[i2]:
                i1 +=1; i2 += 1;
                if i2 == len(needle):
                    return i1 - i2;
            else:
                if i2 == 0:
                    i1 += 1;
                else:
                    i2 = bef[i2-1] + 1;
        return -1;

s=Solution();
print s.strStr("mississippi","issip");
print s.strStr("mississippi","issipi");
        

        
