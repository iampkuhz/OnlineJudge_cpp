/*
 * BestTimetoBuyandSellStock.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int size = prices.size();

    	if(size < 2) return 0;

    	int min = prices[0], maxP = 0;
    	for(int i = 1 ; i < size; i ++)
    	{
    		maxP = maxP < (prices[i] - min) ? (prices[i] - min) : maxP;
    		min = min < prices[i] ? min : prices[i];
    	}
    	return maxP;
    }


};



