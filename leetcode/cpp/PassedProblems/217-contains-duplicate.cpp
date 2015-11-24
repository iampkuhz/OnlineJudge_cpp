/*
 * 217-contains-duplicate.cpp
 * Given an array of integers, find if the array contains any duplicates.
 * Your function should return true if any value appears at least twice in the array,
 * and it should return false if every element is distinct.
 *  Created on: Sep 23, 2015
 *      Author: hanzhe
 */
#include <vector>
#include <iostream>
#include <algorithm>>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if(size < 2)
        	return false;
        for(int i = 1 ; i < size; i ++)
        	if(nums[i] == nums[i-1])
        		return true;
        return false;
    }
};


