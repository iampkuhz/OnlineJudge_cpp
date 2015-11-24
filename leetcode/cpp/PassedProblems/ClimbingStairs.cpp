/*
 * ClimbingStairs.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
	int * a;
    int climbStairs(int n) {
    	a = new int[n + 1];
    	for(int i = 0 ; i < n + 1; i ++)
    		a[i] = 0;
    	a[1] = 1;
    	a[2] = 2;
    	return rec(n);;
    }

    int rec(int n )
    {
    	if(n < 3 || a[n] > 0) return a[n];
    	a[n] = rec(n-1) + rec(n-2);
    	return a[n];
    }

    void test()
    {
    	cout << climbStairs(2) << endl;
    	cout << climbStairs(4) << endl;
    	cout << climbStairs(3) << endl;
    	cout << climbStairs(10) << endl;
    	cout << climbStairs(0) << endl;
    	cout << climbStairs(40) << endl;
    }
};



