/*
 * -summary-ranges.cpp
 *Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

 *
 *  Created on: Sep 25, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;




class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> re;
        if(nums.size() < 1)
        	return re;
        int lb = nums[0], le = nums[0];
        for(int i = 1 ; i < nums.size(); i ++){
        	if(nums[i] == le + 1)
        		le ++;
        	else{
        		re.push_back(merge(lb, le));
        		lb = le = nums[i];
        	}
        }
        re.push_back(merge(lb,le));
        return re;
    }

    string merge(int lb, int le){
		stringstream ss;
		if(lb != le)
			ss << lb << "->" << le;
		else ss << lb;
		return ss.str();
    }
};
