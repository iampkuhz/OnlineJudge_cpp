/*
 * 260-single-number-iii.cpp
 *
 *  Created on: Oct 5, 2015
 *      Author: hanzhe
 */

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, len = nums.size();
        for(int i = 0 ; i < len; i ++)
        	x ^= nums[i];
        int last1bit = x & ~(x-1);
//        cout << "l:" << last1bit << endl;
        int a = 0,b = 0;
        for(int i = 0 ; i < len; i ++){
        	if((nums[i] & last1bit) > 0)
        		a ^= nums[i];
        	else b ^= nums[i];
        }
        vector<int> re;
        re.push_back(a);
        re.push_back(b);
        return re;
    }

    void test(){
    	int a[] = {0,0,1,2};
    	vector<int> va(a,a+4);
    	vector<int>  re= singleNumber(va);
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << " ";
    }
};

