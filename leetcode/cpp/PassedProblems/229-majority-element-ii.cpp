/*
 * 229-majority-element-ii.cpp
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 * The algorithm should run in linear time and in O(1) space.
 *  Created on: Sep 25, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	int size = nums.size();
    	vector<int> re;
    	if(size < 1) return re;
    	int i1 = nums[0], c1 = 1, i2 = nums[0], c2 = 0;
    	for(int i = 0 ; i < size; i ++)
    	{
    		if(nums[i] == i1)
    			c1 ++;
    		else if(nums[i] == i2)
    			c2 ++;
    		else if(c1 == 0){
    			i1 = nums[i];
    			c1 = 1;
    		}else if(c2 == 0){
    			i2 = nums[i];
    			c2 = 1;
    		}else{
    			c2 --; c1 --;
    		}
    	}
    	c1 = 0;
    	c2 = 0;
    	for(int i = 0 ; i < size; i ++){
    		if(nums[i] == i1)
    			c1 ++;
    		else if(nums[i] == i2)
    			c2 ++;
    	}
    	if(c1 > size/3)
    		re.push_back(i1);
    	if(c2 > size/3)
    		re.push_back(i2);
    	return re;
    }

    void test(){
    	int a[] = {1,2};
    	vector<int> va;
    	vector<int> re = majorityElement(va);
    	for(int i = 0 ; i < re.size(); i ++)
    		cout << re[i] << endl;
    }
};


