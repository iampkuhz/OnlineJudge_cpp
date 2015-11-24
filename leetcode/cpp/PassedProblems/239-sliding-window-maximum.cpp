/*
 * 239-sliding-window-maximum.cpp
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
 *  Created on: Oct 3, 2015
 *      Author: hanzhe
 */


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> re;
    	int size = nums.size();
    	if(size == 0)
    		return re;
        vector<int> nextBig(size, size);
        for(int i = size - 2; i >= 0; i --){
        	int nB = i + 1;
        	while(nB < size && nums[i] >= nums[nB])
        		nB = nextBig[nB];
        	nextBig[i] = nB;
        }
        int tM = 0, tS = 0;
        while(tS <= size - k){
        	tM = tS;
        	while(nextBig[tM] < tS + k && nextBig[tM] < size)
        		tM = nextBig[tM];
        	while(nextBig[tM] >= tS + k && tM >= tS && tS + k <= size){
        		re.push_back(nums[tM]);
        		tS ++;
        	}
        }
        return re;
    }

    void test(){
    	int a[] = {1,3,-1,-3,5,3,6,7};
    	vector<int> va(a, a+8);
    	vector<int> re = maxSlidingWindow(va, 3);
    	for(int i = 0; i < re.size(); i ++)
    		cout << re[i] << " ";
    }
};
