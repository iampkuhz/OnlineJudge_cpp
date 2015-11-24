/*
 * 137-single-number-ii.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <tr1/unordered_map>
using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::tr1::unordered_map<int, int> nCnt;
        for(int i = 0 ; i < nums.size(); i ++)
        {
        	if(nCnt.find(nums[i]) == nCnt.end())
        		nCnt[nums[i]] = 1;
        	else{
        		nCnt[nums[i]] ++;
        		if(nCnt[nums[i]] > 2)
        			nCnt.erase(nums[i]);
        	}
        }
        return nCnt.begin()->first;
    }
};
