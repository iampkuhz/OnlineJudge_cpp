/*
 * 154-find-minimum-in-rotated-sorted-array-ii.cpp

 *
 *  Created on: Jul 15, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return re(nums, 0, nums.size() - 1);
    }

    int re(vector<int>& nums, int b, int e)
    {
    	if(b >= e - 1)
    		return nums[b] > nums[e] ? nums[e] : nums[b];
    	int m = (b+e)/2;
    	if(nums[m] < nums[b])
    		return re(nums, b+1, m);
    	else if(nums[b] == nums[e])
    	{
    		if(nums[m] < nums[e])
    			return re(nums, b, m-1);
    		else if(nums[m] > nums[e])
    			return re(nums, m+1, e);
    		else
    		{
    			int r1 = re(nums, b, m);
    			int r2 = re(nums, m+1, e);
    			return r1 > r2 ? r2 : r1;
    		}
    	}

    	/* nums[b] < nums[m]*/
    	else if(nums[b] < nums[e])
    		return nums[b];
    	else return re(nums, m+1, e);
    }
};

