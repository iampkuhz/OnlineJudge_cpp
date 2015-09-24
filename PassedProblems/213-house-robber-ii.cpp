/*
 * 212-house-robber-ii.cpp
 *
 *  Created on: Sep 20, 2015
 *      Author: hanzhe
 */

#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
    	int size = nums.size();
    	if(size < 1)
    		return 0;
    	if(size < 2)
    		return nums[0];
    	int r1 = rob2(nums, 2, nums.size() - 2) + nums[0];
    	int r2 = rob2(nums, 1, nums.size() - 1);
    	return r1 > r2 ? r1 : r2;
    }
    int rob2(vector<int> & ns, int bi, int ei){
    	int len = ei - bi + 1;
    	if(len <= 0) return 0;
    	if(len < 2) return ns[bi];
    	vector<int> mx(ns.size(), 0);
    	mx[bi] = ns[bi];
    	mx[bi+1] = ns[bi] <  ns[bi+1] ? ns[bi+1] : ns[bi];
    	for(int i = bi+2; i <= ei; i ++){
    		mx[i] = myMax(ns[i] + mx[i-2], mx[i-1]);
    	}
    	return mx[ei];
    }
    int myMax(int a, int b){
    	return a > b ? a:b;
    }

    void test(){

    }
};

