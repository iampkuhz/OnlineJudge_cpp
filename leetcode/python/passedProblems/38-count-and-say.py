"""

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
"""
class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        re = 1;
        while n> 1:
            re = self.countAndSay2(re);
            n -=1 ;
        return str(re);
    def countAndSay2(self, n):
        ns = str(n);
        c=ns[0];cn = 1;
        re = '';
        for i in range(1, len(ns)):
            if ns[i] == c:
                cn +=1;
            else:
                re = re + str(cn) + c;
                cn = 1; c = ns[i];
        re = re + str(cn) + c;
        return int(re);

s=Solution();
print s.countAndSay(1);
print s.countAndSay(11);
print s.countAndSay(21);


