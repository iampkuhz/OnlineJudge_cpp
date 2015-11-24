/*
 * 172-factorial-trailing-zeroes.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: hanzhe
 */


#include <iostream>
using namespace std;
/**
 * (d^l)! has (1+d+d^2+...+d^(l-1)) 个 d
 */
class Solution {
public:
    int trailingZeroes(int n) {
    	int c2 = count(n, 2), c5 = count(n, 5);
    	return c2 < c5 ? c2 : c5;
    }
    int count(int n, int b){
    	n /= b;
    	int sum = 0, base = 1, powB = 1;
    	while(n > 0){
    		int m = n % b;
    		sum += m * base;
    		n /= b;
    		powB *= b;
    		base += powB;
    	}
    	return sum;
    }
};
