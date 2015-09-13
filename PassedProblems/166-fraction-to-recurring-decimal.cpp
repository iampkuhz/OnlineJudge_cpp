/*
 * 166-fraction-to-recurring-decimal.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <sstream>
#include <inttypes.h>
#include "memory.h"
using namespace std;
/**
 * be careful of the int64, divided by min int
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	int64_t a = numerator, b = denominator;
    	bool minus = ((a>0 && b < 0) || (a<0 && b>0)) ? true : false;
    	a = a < 0 ? -a : a;
    	b = b < 0 ? -b : b;
//    	cout<< a <<" " << b << endl;
    	int recSize = getRecSize(b);
//    	cout << "recSize:" << recSize << endl;
    	int64_t * rem = new int64_t[recSize];
    	memset(rem, 0, sizeof(int64_t) * recSize);
    	int64_t m = a/b, l = a - m * b;
        ostringstream re;
        if(minus)
        	re << "-";
        re << m;
        bool pt = false;
        int ind = 1;
        rem[0] = l;
        while(l != 0)
        {
        	l *= 10;
        	m = l/b;
        	l = l - b*m;
//        	cout << m << " l:" << l << " b:" << b << endl;
        	if(pt == false){
        		re << ".";
        		pt = true;
        	}
        	re << m;
        	if(l == 0 || rem[ind % recSize] == l)
        		break;
        	rem[ind % recSize] = l;
        	ind ++;
        }
//        cout << "re:" << re.str() << " size:" << recSize << endl;
        if(l != 0){
        	string res = re.str();
        	return res.substr(0, res.size()-recSize) + "(" + res.substr(res.size()-recSize) + ")";
        }
    	return  re.str();
    }

    int getRecSize(int64_t b){
    	int l = 10, size = 1;
    	while(b % 2 == 0)
    		b = b/ 2;
    	while(b % 5 == 0)
    		b = b/ 5;
    	if(b == 1)
    		return 1;
    	/*for b=-2147483648*/
    	if(b < 0)return 1;
    	while(true)
    	{
    		if(l % b == 1)
    			break;
    		l = (l % b) * 10;
    		size ++;
    	}
    	return size;
    }

    void test()
    {
    	cout << fractionToDecimal(-1, -2147483648) << endl;
    	cout << fractionToDecimal(7,12) << endl;
    	cout << fractionToDecimal(1,6) << endl;
    	cout << fractionToDecimal(1,2) << endl;
    	cout << fractionToDecimal(1,-2) << endl;
    	cout << fractionToDecimal(2,1) << endl;
    	cout << fractionToDecimal(-2,1) << endl;
    	cout << fractionToDecimal(2,3) << endl;
    	cout << fractionToDecimal(2,-3) << endl;
    	cout << fractionToDecimal(10,19) << endl;
    	cout << fractionToDecimal(10,-19) << endl;
    	cout << fractionToDecimal(10,11) << endl;
    	cout << fractionToDecimal(-10,11) << endl;
    }
};


