/*
 * 263-ugly-number.cpp
 * Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example,
6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
 *  Created on: Oct 4, 2015
 *      Author: hanzhe
 */

class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0)
        	return false;
        num = d(d(d(num,2),3),5);
        return num == 1;
    }

    int d(int n, int di){
    	while(n % di == 0)
    		n /= di;
    	return n;
    }
};


