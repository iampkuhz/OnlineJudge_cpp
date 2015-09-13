/*
 * 152-maximum-product-subarray.cpp
 *
 *  Created on: Jul 15, 2015
 *      Author: hanzhe
 */

#include <vector>
#include <iostream>
#include <limits.h>
#include "memory.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int * maxP, * minP;
    	int size = nums.size();
    	maxP = new int[size];
    	memset(maxP, INT_MIN, sizeof(int)*size);
    	minP = new int[size];
    	memset(minP, INT_MAX, sizeof(int)*size);
    	int re = nums[0];
    	maxP[0] = minP[0] = nums[0];
    	for(int i = 1 ; i < size; i ++)
    	{
    		maxP[i] = myMax(nums[i], maxP[i-1]*nums[i]);
    		maxP[i] = myMax(maxP[i], minP[i-1]*nums[i]);
    		re = re > maxP[i] ? re : maxP[i];
    		minP[i] = myMin(nums[i], minP[i-1]*nums[i]);
    		minP[i] = myMin(minP[i], maxP[i-1]*nums[i]);
    	}
    	return re;
    }
    int myMin(int a, int b)
    {
    	return a > b ? b : a;
    }
    int myMax(int a, int b)
    {
    	return a > b ? a : b;
    }

    /**
     * failed! Memory Limit Exceeded
     */
    int maxProduct2(vector<int>& nums) {
        int ** prod;
        int size = nums.size();
        prod = new int * [size];
        int re = INT_MIN;
        for(int i = 0 ; i < size; i ++)
        {
        	prod[i] = new int [size];
        	memset(prod[i], INT_MIN, sizeof(int) * size);
        	prod[i][i] = nums[i];
        	re = re < nums[i] ? nums[i] : re;
        }
        /** prod[i][j] = (ai * ... * aj) */
        for(int gp = 2; gp <= size; gp ++)
        	for(int i = 0 ; i < size -gp+1; i ++)
        	{
        		prod[i][i+gp-1] = nums[i] * prod[i+1][i+gp-1];
        		re = re < prod[i][i+gp-1] ? prod[i][i+gp-1] : re;
        	}
        return re;
    }
};


