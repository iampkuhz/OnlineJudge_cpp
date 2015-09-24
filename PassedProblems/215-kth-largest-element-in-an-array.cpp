/*
 * 213-kth-largest-element-in-an-array.cpp
 *
 *  Created on: Sep 20, 2015
 *      Author: hanzhe
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        myQsort(nums, 0, nums.size() - 1);
        return nums[nums.size() -k];
    }

    void myQsort(vector<int> & nums, int bi, int ei){
    	if(bi >= ei) return;
    	int pivot = nums[bi];
    	int f = bi, b = ei;
    	while(f < b){
    		while(nums[b] >= pivot && b > f)
    			b --;
    		if(b > f){
    			nums[f] = nums[b];
    			f ++;
    		}
    		while(nums[f] <= pivot && f < b){
    			f ++;
    		}
    		if(f < b){
    			nums[b] = nums[f];
    			b --;
    		}
    	}
    	nums[f] = pivot;
//    	cout << bi << "," << ei << "," << f << " ";
//    	for(int i = bi ; i <= ei ; i ++)
//    		cout << nums[i] << " ";
//    	cout << endl;
    	myQsort(nums, bi, f-1);
    	myQsort(nums, f+1, ei);
    }

    void test(){
//    	int a[]= {2,45,3,25,23,58};
//    	vector<int> va(a,a+6);
    	int a[]= {-1,2,0};
    	vector<int> va(a,a+3);
    	cout << findKthLargest(va, 1) << endl;
    	for(int i = 0; i < va.size(); i ++)
    		cout << va[i] << " ";
    }
};


