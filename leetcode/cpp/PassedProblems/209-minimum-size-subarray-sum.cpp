/*
 * 209-minimum-size-subarray-sum.cpp
 *
 *  Created on: Sep 17, 2015
 *      Author: hanzhe
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	if(nums.size() < 1) return 0;
        int b = 0, e = 0, sum = 0, size = nums.size();
        int re = 0;
        while(e < size){
        	sum += nums[e];
        	while(sum > s && b < e && sum - nums[b] >= s){
        		sum -= nums[b];
        		b ++;
        	}
//        	cout << e << " sum:" << sum << " b:" << b << endl;
        	if(sum >= s && (re == 0 || re > e-b+1))
        		re = e - b + 1;
        	e ++;
        }
        return re;
    }

    void test(){
    	int va[] = {2,3,1,2,4,3};
    	vector<int> v(va,va+6);
    	cout << minSubArrayLen(7, v) << endl;
    }
};



