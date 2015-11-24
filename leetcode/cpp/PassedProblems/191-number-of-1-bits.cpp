/*
 * 191-number-of-1-bits.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include "stdint.h"
using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n){
		int re = 0;
		int ind = 32;
		while(ind--){
			re += (n & 1);
			n >>=1;
		}
		return re;
	}

	void test(){
		cout << hammingWeight(11) << endl;
	}
};


