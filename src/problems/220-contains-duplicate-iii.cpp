/*
 * 220-contains-duplicate-iii.cpp
 * Given an array of integers, find out whether there are two distinct indices i and j in the array such that
 *  the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 *
 *  Created on: Sep 23, 2015
 *      Author: hanzhe
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
struct ni{
	int v;
	int i;
	ni(int tv, int ti): v(tv), i(ti) {}
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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	vector<ni> n2;
    	int size = nums.size();
    	for(int i = 0 ; i < size; i ++){
    		ni * tn = new ni(nums[i], i);
    		n2.push_back(*tn);
    	}
    	sort(n2.begin(), n2.end(), cmp());
        for(int i = 0 ; i < size; i ++)
        	cout << n2[i].v << " " << n2[i].i << endl;
    	if(size < 2)
    		return false;
    	int bi = 0, ei = 1;
    	while(ei < size){
    		while(bi < ei && ei < size){
    			if(n2[ei].v  <= n2[bi].v + t){
    				for(int i = bi; i < ei; i ++)
        				if(n2[ei].v <= n2[i].v + t && abs(n2[ei].i - n2[i].i) <= k){
        					cout << n2[ei].v << " " <<  n2[ei].i << " " << n2[i].v << n2[i].i << endl;
        					return true;
        				}
    				ei ++;
    			}
    			else bi ++;
    		}
    		ei ++;
    	}
    	return false;
    }

    void test(){
//    	int a[] = {0,10,22,15,0,5,22,12,1,5};
//    	vector<int> ia(a, a+10);
    	    	int a[] = {1,3,6,2};
    	    	vector<int> ia(a, a+4);
//    	    	int a[] = {1,2};
//    	    	vector<int> ia(a, a+2);
    	cout << containsNearbyAlmostDuplicate(ia,1,2) << endl;

    }
};

