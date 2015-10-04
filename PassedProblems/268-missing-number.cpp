/*
 * 268-missing-number.cpp
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
For example,
Given nums = [0, 1, 3] return 2.

 *  Created on: Oct 4, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i ++)
        	sum += nums[i];
        return size* (size + 1)/2 - sum;
    }
};

