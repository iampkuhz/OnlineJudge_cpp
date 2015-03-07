/*
 * Pow(x,n).cpp
 *
 *  Created on: Mar 6, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include "limits.h"
using namespace std;
class Solution {
public:
    double pow(double x, int n) {
    	//cout << x << " " << n << endl;
    	if(x == 0.0) return 0;
        if(n < 0){
        	if((n/2) * 2 == n)
        		return 1.0 / (pow(x, -(n/2)) * pow(x, -(n/2)));
        	else return 1.0 / (pow(x, -(n/2) + 1) * pow(x, -n/2));
        }
        if(n == 0 ) return 1.0;

        return Bpow(1.0, x, n);
        return x * pow(x, n - 1 );
    }

    double Bpow(double re, double pows, int left)
    {
    	if(left <= 0) return re;
    	if(left % 2 == 1) re *= pows;
    	return Bpow(re, pows * pows, left /2 );
    }

    void test(){
    	cout << (-2)/2 << " " << (-4/2) * 2 << endl;
    	cout << pow(34.00515, -3) << endl;
    	cout << pow(2.0, -2) << endl;
    	cout << pow(1.2, 3) << endl;
    	cout << pow(0.3, 4) << endl;
    	cout << pow(1.00001, 123456) << endl;
    	cout << pow(1.00000, -2147483648) << endl;
    	cout << pow(22.14659, -2) << endl;
    }
};



