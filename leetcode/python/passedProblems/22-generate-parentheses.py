"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
"""
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        self.re=[];
        self.rec('', 0,0,n);
        return self.re;

    def rec(self, s, lc, rc, n):
        if lc == n and rc == n:
            self.re.append(s);
            return;
        if lc < n:
            self.rec(s+'(', lc+1, rc, n);
        if rc < lc:
            self.rec(s+')', lc, rc+1, n);
s = Solution();
print s.generateParenthesis(3);
        
