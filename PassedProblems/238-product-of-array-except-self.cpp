/*
 * 238-product-of-array-except-self.cpp
 * Given an array of n integers where n > 1, nums,
 * return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
 *  Created on: Oct 3, 2015
 *      Author: hanzhe
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int size = nums.size();
        vector<int> re;
    	if(size == 0)
    		return re;
    	if(size == 1){
    		re.push_back(nums[0]);
    		return re;
    	}
        vector<int> fProd(size, nums[0]), bProd(size, nums[size-1]);
        for(int i = 1 ; i < size; i ++)
        	fProd[i] = fProd[i-1] * nums[i];
        for(int i = size - 2; i >= 0 ; i --)
        	bProd[i] = bProd[i+1] * nums[i];
        re.push_back(bProd[1]);
        for(int i = 1; i < size - 1; i ++)
        	re.push_back(fProd[i-1] * bProd[i+1]);
        re.push_back(fProd[size-2]);
        return re;
    }

};


