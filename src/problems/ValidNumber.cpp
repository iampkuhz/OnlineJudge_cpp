/*
 * ValidNumber.cpp
 *
 *  Created on: Mar 9, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
    	bool dot = false, bd = false, ad = false, e = false, be = false, ae = false, n = false, in = false;
    	bool mi = false;
        for(int i = 0; i < s.length(); i ++)
        {
        	if(s[i] == '.'){
        		if(dot || e) return false;
        		dot = true;
        	}
        	else if(s[i] == 'e'){
        		if(e) return false;
        		mi = false;
        		e = true;
        	}
        	else if(s[i] == '-' || s[i] == '+')
        	{
        		if((in && !(i >0 && s[i-1] == 'e')) || mi) return false;
        		mi = true;
        		in = true;
        	}
        	else if(! (s[i] >= '0' && s[i] <= '9') && s[i] != ' ')
        		return false;
        	else{
        		if(s[i] != ' ') {
        			if(e) ae = true;
        			else be = true;
        			if(dot) ad = true;
        			else bd = true;
        			n = true;
        		}
        		else if(in){
        			for(; i < s.length(); i ++)
        				if(s[i] != ' ')
        					return false;
        			break;
        		}
        	}
        	if(s[i] != ' '){
        		in = true;
        	}
        }
        bool re = n;
        if(e){
        	re = re && ae && be;
        }
        if(dot)
        	re = re && (ad || bd);
        return re;
    }

    void test()
    {
    	cout << isNumber("0") << endl;
    	cout << isNumber(" 0. 1 ") << endl;
    	cout << isNumber("abc") << endl;
    	cout << isNumber("1a") << endl;
    	cout << isNumber("2e10") << endl;
    	cout << isNumber("2e") << endl;
    	cout << isNumber("e") << endl;
    	cout << isNumber(".") << endl;
    	cout << isNumber("1.") << endl;
    	cout << isNumber(".2") << endl;
    	cout << isNumber("3.") << endl;
    	cout << isNumber(". 1") << endl;
    	cout << isNumber(" ") << endl;
    	cout << isNumber("1 ") << endl;
    	cout << isNumber(". ") << endl;
    	cout << isNumber("-1. ") << endl;
    	cout << isNumber("6+1") << endl;
    	cout << isNumber("6e+1") << endl;
    	cout << isNumber("6-1") << endl;
    	cout << isNumber("6e-1") << endl;
    	cout << isNumber(" -7.e+234") << endl;
    }
};



