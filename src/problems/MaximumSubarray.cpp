/*
 * MaximumSubarray.cpp
 *
 *  Created on: 2015年3月7日
 *      Author: hanzhe
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
    	int *s = new int[n];
    	s[0] = A[0];
        for(int i = 1 ; i < n ;i ++)
        {
        	if(s[i - 1] >0) s[i] = s[i - 1] + A[i];
        	else s[i] = A[i];
        }
        int max = s[0];
        for(int i = 1; i < n ; i++)
        	if(max < s[i])
        		max = s[i];
        return max;
    }

    void test()
    {
    	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    	cout << maxSubArray(a, 9) << endl;
    }
};



