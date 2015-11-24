/*
 * 136-single-number.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::tr1::unordered_map<int, int> nmap;
        for(int i = 0 ; i < nums.size(); i ++)
        {
        	if(nmap.find(nums[i]) == nmap.end())
        		nmap[nums[i]] = 0;
        	else nmap.erase(nums[i]);
        }
        return nmap.begin()->first;
    }
};


