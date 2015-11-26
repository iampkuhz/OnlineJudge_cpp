#-*-coding:utf-8-*-
"""
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
罗马数字是阿拉伯数字传入之前使用的一种数码。罗马数字采用七个罗马字母作数字、即Ⅰ（1）、X（10）、C（100）、M（1000）、V（5）、L（50）、D（500）。记数的方法：
相同的数字连写，所表示的数等于这些数字相加得到的数，如 Ⅲ=3；
小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数，如 Ⅷ=8、Ⅻ=12；
小的数字（限于 Ⅰ、X 和 C）在大的数字的左边，所表示的数等于大数减小数得到的数，如 Ⅳ=4、Ⅸ=9；
在一个数的上面画一条横线，表示这个数增值 1,000 倍，如=5000。

"""

class Solution(object):
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

s= Solution();
print s.intToRoman(1992);
print s.intToRoman(99);
print s.intToRoman(2015);

        
