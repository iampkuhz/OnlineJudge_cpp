/*
 * RemoveElement.cpp
 *
 *  Created on: 2014年10月28日
 *      Author: hanzhe
 */

#include<iostream>
using namespace std;
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
    	if(n == 0)
    		return 0;
    	int ind = 0, cur = 0;
    	while(ind < n)
    	{
    		if(A[ind] != elem)
    		{
    			A[cur] = A[ind];
    			cur ++;
    		}
    		ind ++;
    	}
    	return cur;
    }
};



