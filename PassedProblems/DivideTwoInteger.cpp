/*
 * DivideTwoInteger.cpp
 *
 *  Created on: 2014年10月29日
 *      Author: hanzhe
 */
#include <iostream>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
    	//GetR(divisor);
    	bool minus = false;
    	if(divisor == 0 || divisor == (1<<31))
    	{
    		if(dividend == (1<<31) &&
    				divisor == (1 << 31))
    			return 1;
    		return 0;
    	}
    	int rest = 0;
    	if(dividend < 0)
    	{
    		minus = !minus;
    		if(dividend == (1 << 31))
    		{
    			if(divisor == 1)
    				return 1 << 31;
    			dividend -= 1;
    			rest = 1;
    		}
    		else dividend = -dividend;
    	}
    	if(divisor < 0)
    	{
    		minus = !minus;
    		divisor = - divisor;
    	}
    	//cout << dividend << " " << divisor << endl;
    	int size = 0;
    	int tmp = divisor;
    	while(dividend >= tmp)
    	{
    		tmp <<= 1;
    		//cout << (tmp & (1 << 31)) << " " << tmp << " " << endl;
    		if((tmp & (1 << 31)) == (1 << 31))
    			break;
    		size ++;
    	}
    	tmp = divisor << size;
    	int result = 0;
    	while(size >= 0)
    	{
    		size --;
    		if(dividend >= tmp)
    		{
    			result = (result << 1) + 1;
        		dividend -= tmp;
    		}
    		else result = result << 1;
    		tmp >>= 1;
    	}
		if(dividend + rest >= divisor)
			result ++;
    	//cout << "rest:"; GetR(result);
    	if(minus)
    		result = -result;
    	return result;
    }
    void GetR(int fdata)
    {
    	for(int i = 31; i >= 0 ; i --)
    	{
    		if(1 == ((fdata >> i) & 1))
    			cout << 1;
    		else cout << 0;
    	}
    	cout << endl;
    }
    void test()
    {
    	cout << divide(-2147483648, 2) << endl;
    	for(int i = 0 ; i < 10; i ++)
    	{
    		int i1 = rand();
    		int i2 = rand();
    		i1 = i1 % 100 - 50;
    		i2 = i2 % 10 - 5;
        	cout << i1 << " " << i2 << endl;
    		int result = divide(i1, i2);
    		if(i2 != 0 && result != (i1/i2))
    			cout << "error:" << i1 << ", " << i2 << " " << result << endl;
    		else cout << "result:" << i1 << ", " << i2 << " " << result << endl;
    	}

    }
};



