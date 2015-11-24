/*
 * BestTimetoBuyandSellStockIII.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include "memory.h"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int n = prices.size();

    	if(n < 2) return 0;

    	int * fw = new int[n];
    	int * bw = new int[n];
    	memset(fw, 0, sizeof(int)*n);
    	memset(bw, 0, sizeof(int)*n);

    	int min = prices[0];
    	int maxP1 = 0;
    	for(int i = 1 ; i < n; i ++)
    	{
    		fw[i] = maxP1;
    		fw[i] = (prices[i] - min > fw[i]) ? (prices[i] - min) : fw[i];
    		min = min < prices[i] ? min : prices[i];
    		maxP1 = maxP1 > fw[i] ? maxP1 : fw[i];
    	}

    	int max = prices[n-1];
    	int minP2 = 0;
    	for(int i = n-2; i >= 0 ; i --)
    	{
    		bw[i] = minP2;
    		bw[i] = (prices[i] - max < bw[i]) ?  (prices[i] - max) : bw[i];
    		max = prices[i] > max ? prices[i] : max;
    		minP2 = minP2 < bw[i] ? minP2 : bw[i];
    	}

    	int sMax = 0;
    	for(int i = 0 ; i < n; i ++)
    	{
    		int sum = fw[i] - bw[i];
    		sMax = sMax > sum ? sMax : sum;
    	}
    	return sMax;
    }

    void test()
    {

    }
};


