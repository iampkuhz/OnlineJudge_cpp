/*
 * 189-reverse-bits.cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include "stdint.h"
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	uint32_t n1 = ((n  >> 1) & 0x55555555) | ((n  & 0x55555555) << 1);
    	uint32_t n2 = ((n1 >> 2) & 0x33333333) | ((n1 & 0x33333333) << 2);
    	uint32_t n3 = ((n2 >> 4) & 0x0f0f0f0f) | ((n2 & 0x0f0f0f0f) << 4);
    	uint32_t n4 = ((n3 >> 8) & 0x00ff00ff) | ((n3 & 0x00ff00ff) << 8);
    	uint32_t n5 = ((n4 >> 16) & 0x0000ffff) | ((n4 & 0x0000ffff) << 16);
//    	output(n);
//    	output(n1);
//    	output(n2);
//    	output(n3);
//    	output(n4);
    	return n5;
    }

    void output(uint32_t nt)
    {
    	for(int i = 0 ; i < 32; i ++)
    		cout <<( (nt>>(31-i)) & 1);
    	cout << endl;
    }
    void test(){
    	cout << reverseBits(43261596) << endl;
    }
};


