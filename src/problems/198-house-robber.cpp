/*
 * 198-house-robber.cpp
 *
 *  Created on: Sep 13, 2015
 *      Author: hanzhe
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int size = nums.size();
    	if(size == 0) return 0;
    	if(size == 1) return nums[0];
    	vector<int> sum(nums);
    	sum[0] = nums[0];
    	sum[1] = myMax(nums[0],nums[1]);
    	if(size == 2) return sum[1];
    	for(int i = 2; i < size; i ++){
    		sum[i] = myMax(sum[i-1], sum[i-2] + nums[i]);
    	}
    	return sum[size-1];
    }
    int myMax(int a, int b){
    	return a>b ? a:b;
    }
};
