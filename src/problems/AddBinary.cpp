/*
 * AddBinary.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length(), lb = b.length();
        int i = la-1, j = lb - 1;
        int add = 0;
        string re = "";
        while( i >= 0 && j >= 0)
        {
        	int sum = a[i]-'0' + b[j]- '0' + add;
        	if(sum > 1) add = sum /2;
        	else add = 0;
        	stringstream ss;
        	ss << sum%2;
        	string ts;
        	ss >> ts;
        	re = ts + re;
        	i--;
        	j--;
        }
        if(i >= 0){
        	while(i >= 0){
            	stringstream ss;
            	ss << (a[i] - '0' + add)%2;
            	add = (a[i] - '0' + add)/2;
            	string ts;
            	ss >> ts;
            	re = ts + re;
        		i --;
        	}
        }
        else if(j >= 0){
        	while(j >= 0){
            	stringstream ss;
            	ss << (b[j] - '0' + add)%2;
            	add = (b[j] - '0' + add)/2;
            	string ts;
            	ss >> ts;
            	re = ts + re;
        		j --;
        	}
        }
        if(add > 0)
        	re = "1" + re;
        return re;
    }

    void test()
    {
    	cout << addBinary("101001","11011") << endl;
    	cout << addBinary("100","110010") << endl;
    	cout << addBinary("101001","11011") << endl;
    	cout << addBinary("101001","11011") << endl;
    }
};


