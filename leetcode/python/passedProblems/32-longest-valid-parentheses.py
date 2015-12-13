"""

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
"""

class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack=[];
        re,last = 0,-1;
        for i in range(len(s)):
            if s[i] == '(':
                stack.append(i);
            else:
                if(len(stack)==0):
                    last = i;
                else:
                    stack.pop();
                    if len(stack) == 0:
                        re = max(re, i-last);
                    else:
                        re = max(re, i-stack[len(stack)-1]);
        return re;
                    
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        vleft=[i+1 for i in range(len(s))];
        #print 'vleft:', vleft;
        re = 0;
        for i in range(1, len(s)):
            j = i-1;
            while j >= 0 and vleft[j] != j+1:
                j = vleft[j]-1;
            if j >= 0 and s[i] == ')' and '(' == s[j]:
                vleft[i] = j;
                k=j-1;
                while k >=0 and vleft[k] != k+1:
                    k = vleft[k]-1;
                if k != j-1:
                    vleft[i] = k+1;
            re = re if re > i-vleft[i]+1 else i-vleft[i]+1;
        return re;
        
s=Solution();
print s.longestValidParentheses(')()())');
print s.longestValidParentheses(')()())()()(');
print s.longestValidParentheses('())');
