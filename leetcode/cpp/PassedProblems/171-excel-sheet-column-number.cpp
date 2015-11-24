/*
 * 171-excel-sheet-column-number.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: hanzhe
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        int sum = 0, base = 1;
        for(int i = len-1; i >= 0 ; i --)
        {
        	sum += (s[i] - 'A' + 1) * base;
        	base *= 26;
        }
        return sum;
    }
};


