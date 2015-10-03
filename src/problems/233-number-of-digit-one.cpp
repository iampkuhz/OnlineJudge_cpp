/*
 * 233-number-of-digit-one.cpp
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 *  Created on: Sep 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countDigitOne(int n) {
    	int p = 1, re = 0, tn = 0;
    	while(n > 0){
    		int m = n % 10;
    		re += (n/10) * p + ((m > 0) ? (m > 1 ? p : tn+1) : 0);
//    		int t =(m > 1 ? p : tn+1), t2 =(m > 0) ? (m > 1 ? p : tn+1) : 0;
//    		cout << t << t2 <<  endl;
//    		cout << re << (n/10) * p << endl;
    		tn += m * p;
    		n /= 10;
    		p *= 10;
    	}
    	return re;
    }

    void test(){
    	cout << countDigitOne(13) << endl;
    }
};


