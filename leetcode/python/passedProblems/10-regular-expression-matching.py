#-*-coding:utf-8-*-
"""
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
    bool isMatch(const char *s, const char *p)

    Some examples:
    isMatch("aa","a") → False
    isMatch("aa","aa") → True
    isMatch("aaa","aa") → False
    isMatch("aa", "a*") → True
    isMatch("aa", ".*") → True
    isMatch("ab", ".*") → True
    isMatch("aab", "c*a*b") → True
"""

# 二维数组记录, 速度慢

class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        M=[[False for i in range(1+len(p))] for j in range(1+len(s))];
        M[0][0] = True;
        for j in range(1, len(p)+1):
            if p[j-1] == '*':
                M[0][j] = M[0][j-2];
            for i in range(1,len(s)+1): 
                if p[j-1] == '*':
                    M[i][j] = M[i][j-2];
                    if self.same(s[i-1], p[j-2]): 
                        M[i][j] = M[i][j] or M[i-1][j] or M[i-1][j-2];
                if self.same(s[i-1], p[j-1]):
                    M[i][j] = M[i-1][j-1];
        return M[len(s)][len(p)];

    def same(self, sc, pc):
        return sc == pc or pc == '.';
s=Solution();
print s.isMatch("aa","c*a*");



# 调用 re 模块, 速度慢
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        return re.match("^" + p + "$", s) != None;

# 直接动规超时
#class Solution(object):
#    def isMatch(self, s, p):
#        """
#        :type s: str
#        :type p: str
#        :rtype: bool
#        """
#        return self.isM(s, p, 0, 0);
#
#    def isM(self, s, p, si, sp):
#        if si >= len(s):
#            if sp < len(p) - 1 and p[sp+1] == '*':
#                return self.isM(s, p, si, sp+2);
#            if sp == len(p):
#                return True;
#            return False;
#        if sp >= len(p):
#            return False;
#        if sp < len(p) - 1 and p[sp+1] == '*' and self.isM(s, p, si, sp+2):
#            return True;
#        if s[si] == p[sp] or p[sp] == '.':
#            if sp < len(p) -1 and p[sp+1] == '*':
#                return self.isM(s,p, si+1, sp+2) or self.isM(s, p, si+1, sp);
#            return self.isM(s,p, si+1, sp+1);
#        return False;
#        
