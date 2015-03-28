/*
 * UniqueBinarySearchTrees.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
	int * c;
    int numTrees(int n) {

    	c = new int[n + 1];
    	for(int i = 0; i < n+1; i ++)
    		c[i] = -1;

    	Count(n);
    	return c[n];
    }
    int Count(int n)
    {
    	if(c[n] >= 0) return c[n];

    	int sum = 0;
    	if(n < 2) sum = 1;
    	else
    	{
    		for(int i = 0 ; i < n ; i ++)
    		    sum += Count(i) * Count(n-1-i);
    	}

    	c[n] = sum;
    	return sum;
    }

    void test()
    {
    	cout << numTrees(1) << endl;
    	cout << numTrees(2) << endl;
    	cout << numTrees(3) << endl;
    	cout << numTrees(4) << endl;
    }
};



