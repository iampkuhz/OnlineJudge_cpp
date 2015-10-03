/*
 * 219-contains-duplicate-ii.cpp
 * Given an array of integers and an integer k,
 * find out whether there are two distinct indices i and j in the array such that
 *  nums[i] = nums[j] and the difference between i and j is at most k.
 *  Created on: Sep 23, 2015
 *      Author: hanzhe
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ni{
	int v;
	int i;
	ni(int tv, int ti):v(tv), i(ti){}
};
class Solution {
public:
	struct cmp{
		bool operator()(const ni & n1, const ni & n2){
			if(n1.v == n2.v)
				return n1.i < n2.i;
			return n1.v < n2.v;
		}
	};
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        vector<ni> n2;
        for(int i = 0 ;i < size; i ++){
        	ni *one = new ni(nums[i], i);
        	n2.push_back(*one);
        }
        sort(n2.begin(), n2.end(), cmp());
        for(int i = 0 ; i < size; i ++)
        	cout << n2[i].v << " " << n2[i].i << endl;
        if(size < 2)
        	return false;
        for(int i = 1 ; i < size; i ++){
        	if(n2[i].v == n2[i-1].v && n2[i].i - n2[i-1].i<= k)
        		return true;
        }
        return false;
    }

    void test(){
    	int a[] = {1,2,1};
    	vector<int> ia(a, a+3);
    	cout << containsNearbyDuplicate(ia,2) << endl;
    }
};


