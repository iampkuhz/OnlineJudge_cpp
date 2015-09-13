/*
 * 202-happy-number.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: hanzhe
 */

#include  <iostream>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
    	if(n == 1) return true;
        int r = 170, s = n;
        while(r--){
        	int ns = 0;
        	while(s > 0){
        		ns += (s % 10) * (s % 10);
        		s /= 10;
        	}
        	if(ns == 1)
        		return true;
        	s = ns;
        }
        return false;
    }

    void test(){
    	for(int i = 1; i < (1 << 10); i ++)
    		if(isHappy(i))
    			cout << i << endl;
    }
};


