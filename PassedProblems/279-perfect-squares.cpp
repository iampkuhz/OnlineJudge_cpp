/*
 * 279-perfect-squares.cpp
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 *  Created on: Nov 26, 2015
 *      Author: hanzhe
 */

#include <math.h>
#include <iostream>
using namespace std;


class Solution {
public:
    int numSquares(int n) {
    	int * c = new int[n+1];
    	for(int i = 0 ; i < n+1; i ++)
    		c[i] = 0;
    	c[1] = 1;
    	c[2] = 2;
    	return dpGet(n, c);
    }

    int dpGet(int n, int * c){
    	if(c[n] > 0 || n == 0)
    		return c[n];
    	int k = sqrt(n);
    	int re = n;
    	for(; k>0; k--){
    		int tk = dpGet(n-k*k, c) + 1;
    		if(tk == 1)
    			return 1;
    		re = re < tk ? re : tk;
    	}
    	c[n] = re;
    	return re;
    }

    void test(){
    	Solution *s=new Solution();
    	cout << s->numSquares(12) << endl;
    	cout << s->numSquares(13) << endl;
    	cout << s->numSquares(9) << endl;
    }
};

