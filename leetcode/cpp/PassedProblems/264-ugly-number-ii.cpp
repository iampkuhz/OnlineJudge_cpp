/*
 * 264-ugly-number-ii.cpp
 * Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
 *  Created on: Oct 4, 2015
 *      Author: hanzhe
 */

class Solution {
public:
	int myMin(int a, int b, int c){
		int t = a > b ? b : a;
		return t > c ? c : t;
	}
    int nthUglyNumber(int n) {
    	int * p = new int[n+1];
    	p[0] = 1;
    	int i2 = 0, i3 = 0, i5 = 0;
		int f2 = p[i2] * 2, f3 = p[i3] * 3, f5 = p[i5] * 5;
    	for(int i = 1 ; i < n; i ++){
    		int min = myMin(f2, f3, f5);
    		p[i] = min;
    		if(min == f2)
    			f2 = 2 * p[++i2];
    		if(min == f3)
    			f3 = 3 * p[++i3];
    		if(min == f5)
    			f5 = 5 * p[++i5];
    	}
    	return p[n-1];
    }
};


