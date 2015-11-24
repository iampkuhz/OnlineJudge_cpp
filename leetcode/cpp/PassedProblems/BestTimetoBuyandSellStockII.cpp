/*
 * BestTimetoBuyandSellStockII.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
#include "memory.h"
using namespace std;

/**
 * not mine
 */
class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int size = prices.size();

    	if(size < 2) return 0;

    	int sum = 0;
    	for(int i = 1; i < size; i ++)
    	{
    		if(prices[i] > prices[i-1])
    			sum += prices[i] - prices[i-1];
    	}
    	return sum;
    }


};



