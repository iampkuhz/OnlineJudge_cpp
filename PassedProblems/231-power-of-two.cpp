/*
 * 231-power-of-two.cpp
 * Given an integer, write a function to determine if it is a power of two.
 *  Created on: Sep 28, 2015
 *      Author: hanzhe
 */
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
    	int cnt = 0;
        for(int i = 0 ; i < 31 ; i ++)
        	if((n >> i) & 1 == 1){
        		cnt ++;
        		if(cnt > 1)
        			return false;
        	}
        return cnt == 1 && ((n >> 31) & 1) == 0;
    }
};


