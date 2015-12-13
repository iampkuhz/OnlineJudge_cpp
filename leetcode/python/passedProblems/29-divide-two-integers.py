"""
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
"""

class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == -(1<<31) and divisor== -1:
            return (1<<31)-1;
        re=0;k=0;
        minus = 0 if dividend <0 else 1;
        minus += 0 if divisor < 0 else 1;
        dividend = dividend if dividend > 0 else -dividend;
        divisor = divisor if divisor > 0 else -divisor;
        while dividend >= (divisor<<1):
            k += 1; divisor <<= 1;
        while k >= 0:
            k -= 1;
            re *= 2;
            if dividend >= divisor:
                re += 1;
                dividend -= divisor;
            divisor >>= 1;
        re = re if minus!=1 else -re;
        return re;

s=Solution();
print s.divide(12,3);
print s.divide(12,-3);
print s.divide(144,12);
print s.divide(144,-12);
print s.divide(10,2);
print s.divide(10,-2);
        
