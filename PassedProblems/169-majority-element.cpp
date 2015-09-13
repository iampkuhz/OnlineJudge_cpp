/*
 * 169-majority-element.cpp
 *
 *  Created on: Aug 1, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return nums[Maj(nums, 0, nums.size()-1)];
    }

    int Maj(vector<int>& ns, int b, int e){
    	if(b+2 > e) return b;
    	int m = (b+e)/2;
    	int i1 = Maj(ns, b, m);
    	int i2 = Maj(ns, m+1, e);
    	return count(ns, b, e, ns[i1]) > count(ns, b, e, ns[i2]) ? i1 : i2;
    }

    int count(vector<int>& ns, int b, int e, int v){
    	int re = 0;
    	for(int i = b ; i <=e; i ++)
    		if(ns[i] == v)
    			re ++;
    	return re;
    }
};


