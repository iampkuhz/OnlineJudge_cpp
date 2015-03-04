/*
 * CountandSay.cpp
 *
 *  Created on: Mar 4, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include "memory.h"
#include "string.h"
#include <sstream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
    	string next = "1";
    	n --;
    	while(n--)
    		next = GetNext(next);
    	return next;
    }

    string GetNext(string n){

    	//cout << "n:" << n  << endl;
    	stringstream ss;
    	if(n.length() < 2)
    		return "1" + n;
    	int ind = n.length();
        int i = 1;
        int lastA = n[0] - '0';
        int lastL = 1;
        string out = "";
        while(i < n.length())
        {
        	if((n[i] - '0') == lastA)
        		lastL ++;
        	else{
        		ss.clear();
        		ss << lastL << lastA;
                //cout << lastL << " a:" << lastA << " i:" << i << endl;
        		string ts;
        		ss >> ts;
        		out += ts;
        		lastA = n[i] - '0';
        		lastL = 1;
        	}
        	i ++;
        }
        ss.clear();
        ss << lastL << lastA;
        string ts;
        ss >> ts;
        //cout << lastL << " a:" << lastA << endl;
        out += ts;
        return out;
    }
    void test()
    {
    	cout << countAndSay(1) << endl;
    	cout << countAndSay(2) << endl;
    	cout << countAndSay(3) << endl;
    	cout << countAndSay(4) << endl;
    }
};



