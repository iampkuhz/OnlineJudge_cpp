#-*-coding:utf-8-*-
"""
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
"""

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        v={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        re = 0;
        if len(s) == 0:
            return re;
        for i in range(len(s)):
            tv= v[s[i]];
            if i < len(s)-1 and v[s[i+1]] > v[s[i]]:
                tv = -tv;
            re += tv;
        return re;

    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        ten=["","I","II","III","IV","V","VI","VII","VIII","IX","X"];
        hundred=["","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C"];
        thousands=["","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M"];
        k=["","M","MM","MMM"];
        re = k[num/1000] + thousands[(num%1000)/100] + hundred[(num%100)/10] + ten[num%10];
        return re;


s=Solution();
print "1992,", s.romanToInt(s.intToRoman(1992));
print "2349,", s.romanToInt(s.intToRoman(2349));
print "182,", s.romanToInt(s.intToRoman(182));

        
