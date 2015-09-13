/*
 * 164-maximum-gap.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "memory.h"
#include "limits.h"
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
    	if(nums.size() < 2)
    		return 0;
    	int size = nums.size();
        int maxE = *max_element(nums.begin(), nums.end());
        int minE = *min_element(nums.begin(), nums.end());
        int gap = (maxE - minE)/size + 1;
        int * maxB = new int[size];
        int * minB = new int[size];
        for(int i = 0 ; i < size; i ++)
        {
        	maxB[i] = INT_MAX;
        	minB[i] = INT_MIN;
        }
        for(int i = 0 ; i < size; i ++)
        {
        	int bId = (int)((nums[i] - minE)/gap);
        	if(nums[i] > maxB[bId] || maxB[bId] == INT_MAX)
        		maxB[bId] = nums[i];
        	if(minB[bId] == INT_MIN || nums[i] < minB[bId])
        	{
        		minB[bId] = nums[i];
//        		cout << "PP:" << minB[bId] << endl;
        	}
//        	else cout<< "not:" << minB[bId] << " " << INT_MIN << endl;
//        	cout << bId << " " << maxB[bId] << " " << minB[bId] << endl;
        }
        /* minE in bucket[0]*/
        int re = 0;
        int lastMax = maxB[0];
        for(int i = 1 ; i < size;  i ++)
        {
        	if(maxB[i] == INT_MAX)
        		continue;
//        	cout << i <<" " << maxB[i]<< " " << lastMax << endl;
        	re = re > (minB[i] - lastMax) ? re : (minB[i] - lastMax);
        	lastMax = maxB[i];
        }
        return re;
    }

    void test()
    {
    	int a[] = {1,1,1,5,5,5,5,5,5};
    	vector<int> in(a,a+8);
    	cout << maximumGap(in) << endl;
    }
};
