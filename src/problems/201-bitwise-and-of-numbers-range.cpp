/*
 * 201-bitwise-and-of-numbers-range.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: hanzhe
 */

#include <iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int re = 0;
        int gap = n-m +1;
        int ind = 32;
        while(ind --){
        	re = re * 2;
        	int s = ((m >> (ind)) & (n >> (ind))) & 1;
        	s = (gap > (1 << (ind))) ? 0 : s;
        	re += s;
//        	cout << s << " " << (1 << (ind)) << " " << ((n >> (ind)) & 1) << " " << ((m >> (ind)) &1)<< endl;;
        }
        return re;
    }

    void test(){
    	cout << rangeBitwiseAnd(5,5) << endl;
    }
};


