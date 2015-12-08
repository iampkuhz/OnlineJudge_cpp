"""
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
"""
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if len(s) < 1:
            return True;
        st=[];
        myMap={']':'[',')':'(','}':'{'};
        for i in range(len(s)):
            if s[i] == '(' or s[i] == '[' or s[i] == '{':
                st.append(s[i]);
            elif len(st) < 1:
                return False;
            else:
                top = st.pop();
                if top != myMap[s[i]]:
                    return False;
        if len(st)>0:
            return False;
        return True;


s = Solution();
print s.isValid("()");
print s.isValid("()[]{}");
print s.isValid("(]");
print s.isValid("([)]");
