/*
 * 162-find-peak-element.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: hanzhe
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ind = 0;
        for(int i = 1 ; i < nums.size(); i ++)
        {
        	if(nums[i] > nums[i-1])
        	{
        		ind = i;
            	if(i < nums.size()-1 && nums[i] > nums[i+1])
            		return i;
        	}
        }
        return ind;
    }
};

