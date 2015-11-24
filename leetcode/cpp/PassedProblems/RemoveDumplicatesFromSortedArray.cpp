/*
 * RemoveDumplicatesFromSortedArray.cpp
 *
 *  Created on: 2014年10月28日
 *      Author: hanzhe
 */

#include<iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n == 0)
    		return 0;
    	int ind = 1, curNr = 0;
    	while(ind < n)
    	{
    		if(A[ind] != A[curNr])
    		{
    			curNr ++;
    			A[curNr] = A[ind];
    		}
    		ind ++;
    	}
    	return curNr + 1;
    }
};



