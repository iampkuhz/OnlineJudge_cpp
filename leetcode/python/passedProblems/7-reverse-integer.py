#Reverse digits of an integer.

#Example1: x = 123, return 321
#Example2: x = -123, return -321 

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        re = 0;
        minus = (x >= 0 and 1 or 0);
        #print minus
        #print x, ",", (x>=0)
        x = x > 0 and x or -x;
        while x != 0:
            res = x % 10;
            re = re * 10 + res;
            x /= 10;
        re = minus == 0 and -re or re;
        re = 0 if (re > 2147483647 or re < - 2147483648) else re ;
        return re;

s = Solution();
#print s.reverse(123);
print s.reverse(1534236469);
#print s.reverse(-123);


        
