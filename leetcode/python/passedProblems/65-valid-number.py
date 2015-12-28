#!/usr/bin/env python
# encoding: utf-8

"""
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
"""

class Solution(object):
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        try:
            x=float(s)
        except:
            return False
        return True

s=Solution()
print s.isNumber("0")
print s.isNumber(" 0.1")
print s.isNumber("abc")
print s.isNumber("1 a")
print s.isNumber("2e10")

